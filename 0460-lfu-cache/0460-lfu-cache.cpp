class LFUCache {
public:
    int minfreq, size;
    unordered_map<int, pair<int, int>>keyval;
    unordered_map<int, list<int>>freqlist;
    unordered_map<int, list<int>::iterator>pos;
    LFUCache(int capacity) {
        size=capacity;
        minfreq=0;
    }
    void updatefreq(int key){
        
        int curr_freq = keyval[key].second;
        freqlist[curr_freq].erase(pos[key]);
        pos.erase(key);
        
        keyval[key].second++;
        curr_freq=keyval[key].second;
        freqlist[curr_freq].push_back(key);
        pos[key]=--freqlist[curr_freq].end();
        
        if(freqlist[minfreq].empty()){
            minfreq++;
        }
    }
    
    int get(int key) {
        if(!keyval.count(key)) return -1;
        updatefreq(key);
        return keyval[key].first;
    }
    
    void put(int key, int value) {
        if(size==0) return;
        
        if(keyval.count(key)){
            keyval[key].first=value;
            updatefreq(key);
            return;
        }
        if(keyval.size()==size){
            int delkey = freqlist[minfreq].front();
            freqlist[minfreq].pop_front();
            keyval.erase(delkey);
            pos.erase(delkey);
        }
        keyval[key]={value, 1};
        freqlist[1].push_back(key);
        pos[key]=--freqlist[1].end();
        minfreq=1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */