class LRUCache {
public:
    unordered_map<int, int>mp;
    unordered_map<int, list<int>::iterator>address;
    list<int>l;
    int size;
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        
        if(mp.find(key)==mp.end()) return -1;
        l.erase(address[key]);
        address.erase(key);
        l.push_front(key);
        address[key]=l.begin();
        return mp[key];
            
    }
    
    void put(int key, int value) {
        
        
        if(mp.find(key)!=mp.end()){
            l.erase(address[key]);
            address.erase(key);
            mp.erase(key);
        }
        int n = l.size();
        if(n==size){
            int k = l.back();
            l.pop_back();
            address.erase(k);
            mp.erase(k);
        }
        l.push_front(key);
        address[key]=l.begin();
        mp[key]=value;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */