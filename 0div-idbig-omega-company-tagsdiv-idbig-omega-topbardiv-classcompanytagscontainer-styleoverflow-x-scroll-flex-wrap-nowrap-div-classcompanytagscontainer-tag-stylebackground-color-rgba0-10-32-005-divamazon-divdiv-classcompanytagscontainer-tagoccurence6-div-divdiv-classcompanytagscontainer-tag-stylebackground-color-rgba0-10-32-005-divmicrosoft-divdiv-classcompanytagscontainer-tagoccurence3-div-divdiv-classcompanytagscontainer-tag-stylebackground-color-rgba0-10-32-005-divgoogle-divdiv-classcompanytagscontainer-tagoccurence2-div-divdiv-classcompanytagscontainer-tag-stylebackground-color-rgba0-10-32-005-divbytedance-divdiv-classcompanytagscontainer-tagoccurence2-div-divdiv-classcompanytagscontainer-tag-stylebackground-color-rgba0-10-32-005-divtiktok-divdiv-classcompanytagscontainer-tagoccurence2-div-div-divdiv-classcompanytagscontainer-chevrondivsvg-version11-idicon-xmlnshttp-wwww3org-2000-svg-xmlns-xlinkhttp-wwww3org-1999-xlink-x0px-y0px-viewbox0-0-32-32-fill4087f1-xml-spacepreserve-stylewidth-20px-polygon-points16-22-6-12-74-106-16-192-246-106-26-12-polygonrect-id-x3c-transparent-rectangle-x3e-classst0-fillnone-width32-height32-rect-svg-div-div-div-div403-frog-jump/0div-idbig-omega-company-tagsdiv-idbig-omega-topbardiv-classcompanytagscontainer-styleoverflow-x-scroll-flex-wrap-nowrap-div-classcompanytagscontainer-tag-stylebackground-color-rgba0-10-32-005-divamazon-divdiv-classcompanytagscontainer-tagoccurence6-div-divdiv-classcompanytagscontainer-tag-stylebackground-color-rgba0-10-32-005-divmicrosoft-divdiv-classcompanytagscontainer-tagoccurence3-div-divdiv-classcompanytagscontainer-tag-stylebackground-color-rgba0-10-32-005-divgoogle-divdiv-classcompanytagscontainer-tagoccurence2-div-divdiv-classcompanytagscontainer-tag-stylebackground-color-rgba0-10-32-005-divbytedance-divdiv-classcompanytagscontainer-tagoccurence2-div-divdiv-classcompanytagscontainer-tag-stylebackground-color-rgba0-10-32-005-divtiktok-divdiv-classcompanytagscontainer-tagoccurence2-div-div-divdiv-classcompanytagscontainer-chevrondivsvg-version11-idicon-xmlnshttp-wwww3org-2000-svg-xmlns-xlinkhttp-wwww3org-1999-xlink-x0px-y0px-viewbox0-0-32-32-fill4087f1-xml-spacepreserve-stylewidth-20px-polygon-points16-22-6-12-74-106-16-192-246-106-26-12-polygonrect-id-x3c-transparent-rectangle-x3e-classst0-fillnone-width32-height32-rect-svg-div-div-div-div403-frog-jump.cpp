class Solution {
public:
    bool canCross(vector<int>& stones) {
        
        int n = stones.size();
        unordered_map<int, set<int>>mp;
        mp[stones[0]].insert(1);
        for(int i=1;i<n;i++){
            mp[stones[i]];
        }
        
        for(int i=0;i<n;i++){
            int num = stones[i];
            
            for(auto it: mp[num]){
                int pos = num+it;
                if(pos==stones[n-1]){
                    return true;
                }
                if(mp.find(pos)!=mp.end()){
                    if(it-1>0){
                        mp[pos].insert(it-1);
                    }
                    mp[pos].insert({it, it+1});
                }
            }
        }
        
        return false;
    }
};