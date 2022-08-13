class Solution {
public:
    int coinChange(vector<int>& coins , int amount) {
        int n = coins.size();
        int dp[n+1][amount+1];
        
        for(int i=0;i<=amount;i++){
            dp[0][i]=INT_MAX-1;
        }
        
        for(int j=1;j<=n;j++){
            dp[j][0]=0;
        }
        
        for(int j=1;j<=amount;j++){
            
            if(j%coins[0]==0){
                dp[1][j]=(j/coins[0]);
            }
            else{
                dp[1][j]=1e9-1;
            }
            
        }
        
        
        for(int i=2;i<=n;i++){
            for(int j=1;j<=amount;j++){
                
                if(coins[i-1]<=j){
                    dp[i][j] = min(dp[i][j-coins[i-1]] + 1 ,  dp[i-1][j]);
                }
                else{
                     dp[i][j] = dp[i-1][j];
                }
                
            }
        }
        
        int ans = dp[n][amount];
        if(ans>=1e9-1){
            return -1;
        }
        else{
            return ans;
        }
    }
};