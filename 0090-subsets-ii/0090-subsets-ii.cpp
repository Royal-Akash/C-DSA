// class Solution {
// public:
//     vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//         set<vector<int>>st;
//         int n = nums.size();
        
//         for(int i=0;i<(1<<n);i++){
//             vector<int>ans;
//             for(int j=0;j<n;j++){
//                 if(i&(1<<j)){
//                     ans.push_back(nums[j]);
//                 }
//             }
//             sort(ans.begin(), ans.end());
//             st.insert(ans);
//         }
//         vector<vector<int>>ans;
//         for(auto it : st){
//             ans.push_back(it);
//         }
//         return ans;
//     }
// };


class Solution {
public:
    void findsubset(int ind, vector<int>&nums, vector<int>&ans, vector<vector<int>>&dup){
        
        dup.push_back(ans);
        for(int i=ind;i<nums.size();i++){
            if(i!=ind && nums[i]==nums[i-1]) continue;
            
            ans.push_back(nums[i]);
            findsubset(i+1, nums, ans, dup);
            ans.pop_back();
        }
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>ans;
        vector<vector<int>>dup;
        sort(nums.begin(), nums.end());
        findsubset(0, nums, ans, dup);
        return dup;
    }
};