class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2!=0) return false;
        sum = sum/2;
        
        vector<vector<bool>>dp(n, vector<bool>(sum+1, 0));
        
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
        if(nums[0]<=sum) dp[0][nums[0]];
        
        for(int i=1;i<n;i++){
            for(int target = 1;target<=sum;target++){
                int notake = dp[i-1][target];
                int take = false;
                if(nums[i]<=target) take = dp[i-1][target-nums[i]];
                
                dp[i][target]=take | notake;
            }
        }
        return dp[n-1][sum];
    }
};