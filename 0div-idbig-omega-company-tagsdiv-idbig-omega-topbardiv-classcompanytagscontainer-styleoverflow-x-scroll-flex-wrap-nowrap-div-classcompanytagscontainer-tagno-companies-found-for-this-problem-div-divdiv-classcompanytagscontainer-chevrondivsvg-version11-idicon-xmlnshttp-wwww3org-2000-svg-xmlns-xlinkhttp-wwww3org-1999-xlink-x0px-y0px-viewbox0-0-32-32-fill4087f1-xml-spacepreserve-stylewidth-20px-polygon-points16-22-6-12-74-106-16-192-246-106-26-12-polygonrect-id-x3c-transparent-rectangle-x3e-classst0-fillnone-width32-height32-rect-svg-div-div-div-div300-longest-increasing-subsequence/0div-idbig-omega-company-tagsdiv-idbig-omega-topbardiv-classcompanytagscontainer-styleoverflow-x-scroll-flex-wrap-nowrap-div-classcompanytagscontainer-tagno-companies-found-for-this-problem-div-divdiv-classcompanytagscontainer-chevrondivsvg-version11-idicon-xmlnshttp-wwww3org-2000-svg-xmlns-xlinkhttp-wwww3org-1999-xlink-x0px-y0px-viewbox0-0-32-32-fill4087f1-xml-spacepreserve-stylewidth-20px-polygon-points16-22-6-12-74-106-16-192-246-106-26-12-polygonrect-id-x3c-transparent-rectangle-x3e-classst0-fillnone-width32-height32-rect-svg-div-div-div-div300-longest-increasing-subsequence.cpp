class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
//         vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
        
//         for(int i=n-1;i>=0;i--){
            
//             for(int prev = i-1;prev>=-1;prev--){
                
//                 int len = dp[i+1][prev+1];
                
//                 if(prev==-1 || nums[i]>nums[prev+1]){
//                     len = max(len, 1 + dp[i+1][i+1]);
//                 }
//                 dp[i][prev+1]=len;
//             }
            
//         }
//         return dp[0][0];
        
        if(n==1) return 1;
        int maxi = 0;
        vector<int>dp(n, 1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                
                if(nums[i]>nums[j]){
                    dp[i]=max(dp[i], 1+dp[j]);
                }
            }
            maxi=max(maxi, dp[i]);
        }
        
        return maxi;
        
    }
};