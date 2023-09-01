class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0], nums[1]);
        vector<int>dp(n-1, 0);
        dp[0]=nums[0];
        for(int i=1;i<n-1;i++){
            int take = nums[i];
            if(i>1){
                take+=dp[i-2];
            }
            int notake = dp[i-1];
            dp[i]=max(take, notake);
        }
        int max1 = dp[n-2];
        
        dp[0]=nums[1];
        for(int i=2;i<n;i++){
            int take = nums[i];
            if(i>2){
                take+=dp[i-3];
            }
            int notake = dp[i-2];
            dp[i-1]=max(take, notake);
        }
        return max(max1, dp[n-2]);
    }
};