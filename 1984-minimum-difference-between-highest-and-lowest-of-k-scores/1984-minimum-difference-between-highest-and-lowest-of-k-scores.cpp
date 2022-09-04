class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
         int n = nums.size();
         sort(nums.begin(), nums.end());
        
        int ans = nums[k-1]-nums[0];
        // for(int i=2;i<=n-k;i++){
        //     ans=min(ans , nums[k-1+i]-nums[i]);
        // }
        for(int i=k;i<nums.size();i++){
            ans=min(ans,nums[i]-nums[i-k+1]);
        }
        return ans;
    }
};