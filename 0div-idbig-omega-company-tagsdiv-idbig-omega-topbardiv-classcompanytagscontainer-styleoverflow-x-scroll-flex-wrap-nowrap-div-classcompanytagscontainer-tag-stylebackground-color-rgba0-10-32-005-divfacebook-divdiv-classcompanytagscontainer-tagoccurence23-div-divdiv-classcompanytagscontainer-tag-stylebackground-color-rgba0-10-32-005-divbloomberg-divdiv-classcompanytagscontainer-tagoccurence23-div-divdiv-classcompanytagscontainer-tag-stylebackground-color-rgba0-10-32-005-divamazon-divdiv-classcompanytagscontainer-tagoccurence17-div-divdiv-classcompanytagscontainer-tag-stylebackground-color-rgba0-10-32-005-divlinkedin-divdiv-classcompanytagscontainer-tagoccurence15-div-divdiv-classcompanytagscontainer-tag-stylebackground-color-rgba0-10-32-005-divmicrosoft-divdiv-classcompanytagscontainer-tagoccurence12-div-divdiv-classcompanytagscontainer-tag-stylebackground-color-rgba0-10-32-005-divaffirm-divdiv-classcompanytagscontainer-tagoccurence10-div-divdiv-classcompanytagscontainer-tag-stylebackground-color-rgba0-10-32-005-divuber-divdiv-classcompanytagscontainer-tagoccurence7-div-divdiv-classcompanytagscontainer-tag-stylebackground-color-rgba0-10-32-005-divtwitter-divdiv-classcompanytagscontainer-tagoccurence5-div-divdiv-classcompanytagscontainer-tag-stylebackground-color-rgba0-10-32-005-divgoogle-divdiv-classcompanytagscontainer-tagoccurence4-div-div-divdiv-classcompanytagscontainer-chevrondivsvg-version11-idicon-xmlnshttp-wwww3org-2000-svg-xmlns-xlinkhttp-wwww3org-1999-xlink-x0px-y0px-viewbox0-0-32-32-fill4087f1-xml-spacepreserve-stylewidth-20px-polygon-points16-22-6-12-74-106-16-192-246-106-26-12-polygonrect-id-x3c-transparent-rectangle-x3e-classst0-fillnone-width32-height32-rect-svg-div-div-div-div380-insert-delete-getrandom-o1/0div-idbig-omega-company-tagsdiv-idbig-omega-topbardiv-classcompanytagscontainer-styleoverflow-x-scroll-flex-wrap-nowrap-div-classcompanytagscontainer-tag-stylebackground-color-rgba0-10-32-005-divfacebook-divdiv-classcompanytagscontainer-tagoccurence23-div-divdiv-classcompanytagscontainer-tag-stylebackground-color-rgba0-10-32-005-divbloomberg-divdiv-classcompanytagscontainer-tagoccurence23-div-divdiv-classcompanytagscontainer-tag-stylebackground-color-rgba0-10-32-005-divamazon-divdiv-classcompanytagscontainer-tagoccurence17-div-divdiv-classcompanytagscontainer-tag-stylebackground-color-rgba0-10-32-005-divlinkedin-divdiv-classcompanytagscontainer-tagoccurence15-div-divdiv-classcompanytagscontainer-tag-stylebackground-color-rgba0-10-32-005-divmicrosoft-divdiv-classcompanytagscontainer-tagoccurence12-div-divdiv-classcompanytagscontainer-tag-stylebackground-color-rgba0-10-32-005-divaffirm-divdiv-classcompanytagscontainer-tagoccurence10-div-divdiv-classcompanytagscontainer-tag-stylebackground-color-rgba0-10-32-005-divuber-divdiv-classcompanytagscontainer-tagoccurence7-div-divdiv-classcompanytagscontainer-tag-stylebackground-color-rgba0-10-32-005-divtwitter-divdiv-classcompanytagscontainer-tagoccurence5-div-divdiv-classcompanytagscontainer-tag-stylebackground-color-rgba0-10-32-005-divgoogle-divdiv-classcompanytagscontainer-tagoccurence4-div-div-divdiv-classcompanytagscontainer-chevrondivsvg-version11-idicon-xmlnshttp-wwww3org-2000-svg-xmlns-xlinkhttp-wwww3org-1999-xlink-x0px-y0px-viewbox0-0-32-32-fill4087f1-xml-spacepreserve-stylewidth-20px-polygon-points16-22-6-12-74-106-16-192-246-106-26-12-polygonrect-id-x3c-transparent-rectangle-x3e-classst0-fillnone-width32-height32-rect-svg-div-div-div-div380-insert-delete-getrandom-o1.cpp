class RandomizedSet {
public:
    vector<int>arr;
    unordered_map<int, int>mp;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.count(val)) return false;
        
        arr.push_back(val);
        mp[val]=arr.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(!mp.count(val)) return false;
        
        int idx = mp[val];
        int num = arr.back();
        
        arr[idx]=num;
        arr.pop_back();
        mp[num]=idx;
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        int rand_idx = rand() % arr.size();
        return arr[rand_idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */