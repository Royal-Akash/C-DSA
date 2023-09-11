class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& gs) {
        
        int n = gs.size();
        unordered_map<int, vector<int>>mp;
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            if(mp[gs[i]].size()<gs[i]){
                mp[gs[i]].push_back(i);
            }
            else{
                ans.push_back(mp[gs[i]]);
                mp.erase(gs[i]);
            }
            if(mp[gs[i]].size()==gs[i]){
                ans.push_back(mp[gs[i]]);
                mp.erase(gs[i]);
            }
        }
        return ans;
        
    }
};