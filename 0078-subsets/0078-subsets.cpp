// class Solution {
// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<vector<int>>all_subset;
//         int n = nums.size();
//         for(int i=0;i<(1<<n);i++){
//             vector<int>ans;
//             for(int j=0;j<n;j++){
//                 if(i&(1<<j)){
//                     ans.push_back(nums[j]);
//                 }
//             }
//             all_subset.push_back(ans);
//         }
//         return all_subset;
//     }
// };



class Solution {
public:
    
    void sum(int ind, vector<int>sum1, vector<int>nums, int n, vector<vector<int>>&ans){
        if(ind>=n){
            ans.push_back(sum1);
            return;
        }
        
        sum(ind+1, sum1, nums, n, ans);
        sum1.push_back(nums[ind]);
        sum(ind+1, sum1, nums, n, ans);
        sum1.pop_back();
    }
    
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>>ans;
        vector<int>sum1;
        sum(0, sum1, nums, n, ans);
        return ans;
        
    }
};