class Solution {
public:
    void findcombo(int ind, vector<int>&ds, vector<int>& candidates, int target, vector<vector<int>>&ans){
        
        if(ind==candidates.size()){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }
        
        if(target>=candidates[ind]){
            ds.push_back(candidates[ind]);
            findcombo(ind, ds, candidates, target-candidates[ind], ans);
            ds.pop_back();
        }
        
        findcombo(ind+1, ds, candidates, target, ans);
           
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        findcombo(0, ds, candidates, target, ans);
        return ans;
        
    }
};