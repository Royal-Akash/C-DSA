class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>>st;
        int n = nums.size();
        int psize = 1;
        for(int i=1;i<=n;i++){
            psize=psize*i;
        }
        while(psize--){
            next_permutation(nums.begin(), nums.end());
            st.insert(nums);
        }
        vector<vector<int>>ans;
        for(auto it:st){
            ans.push_back(it);
        }
        return ans;
    }
};