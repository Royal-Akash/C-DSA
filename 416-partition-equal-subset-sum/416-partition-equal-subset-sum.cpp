class Solution {
public:
    bool canPartition(vector<int>& nums) {
         int sum=0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        int ts = sum/2;
        vector<vector<int>> dp(n+1 , vector<int>(sum+1));
        
        if(n==0 && sum!=0){
            return false;
        }
        if(sum%2!=0){
            return false;
        }
        
        else{
            
            for(int i=0;i<n+1;i++){
            for(int j=0;j<ts+1;j++){
                if(i==0){
                    dp[i][j]=false;
                }
                else if(j==0){
                    dp[i][j]=true;
                }
                else if(nums[i-1]<=j){
                    dp[i][j]=dp[i-1][j-nums[i-1]] || dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
                
            }
        }    
     }
        
        return dp[n][ts];
    }
};