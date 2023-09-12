class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int tsum = 0;
        for(int i=0;i<n;i++){
            tsum+=nums[i];
        }
        
        int sum = tsum-target;
        if(sum<0 || sum%2!=0) return 0;
        sum=sum/2;
        vector<vector<int>>dp(n, vector<int>(sum+1, 0));
        
        if(nums[0]==0) dp[0][0]=2;
        else dp[0][0]=1;
        
        if(nums[0]!=0 && nums[0]<=sum) dp[0][nums[0]]=1;
        
        for(int i=1;i<n;i++){
            for(int j=0;j<=sum;j++){
                int notake = dp[i-1][j];
                int take = 0;
                if(j>=nums[i]) take = dp[i-1][j-nums[i]];
                dp[i][j]=take + notake;
            }
        }
        return dp[n-1][sum];
        
    }
};