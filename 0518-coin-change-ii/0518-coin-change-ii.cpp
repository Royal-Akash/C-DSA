class Solution {
public:
    int change(int amt, vector<int>& coins) {
         int n = coins.size();
        // int ans = fun(coins, amount, n-1);
        // if(ans>=1e9) return -1;
        // return ans;
        
        vector<vector<int>>dp(n, vector<int>(amt+1, 0));
        for(int i=0;i<=amt;i++){
            if(i%coins[0]==0){
                dp[0][i]=1;
            }
            else{
                dp[0][i]=0;
            }
        }
        
        for(int i=1;i<n;i++){
            for(int j=0;j<=amt;j++){
                
                int notake = dp[i-1][j];
                int take = 0;
                if(j>=coins[i]) take = dp[i][j-coins[i]];
                dp[i][j]=(take + notake);
            }
        }
        return dp[n-1][amt];
    }
};