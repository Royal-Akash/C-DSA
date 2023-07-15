class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>all_subset;
        int n = nums.size();
        for(int i=0;i<(1<<n);i++){
            vector<int>ans;
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    ans.push_back(nums[j]);
                }
            }
            all_subset.push_back(ans);
        }
        return all_subset;
    }
};