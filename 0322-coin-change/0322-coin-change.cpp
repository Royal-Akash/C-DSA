class Solution {
public:
//     int fun(vector<int>&coins, int tar, int i){
//         if(i==0){
//             if(tar%coins[0]==0) return tar/coins[0];
//             return 1e9;
//         }
        
//         int notake = fun(coins, tar, i-1);
//         int take = INT_MAX;
//         if(tar>=coins[i]) take = 1+fun(coins, tar-coins[i], i);
        
//         return min(take, notake);
        
//     }
    int coinChange(vector<int>& coins, int amt) {
        
        int n = coins.size();
        // int ans = fun(coins, amount, n-1);
        // if(ans>=1e9) return -1;
        // return ans;
        
        vector<vector<int>>dp(n, vector<int>(amt+1, 0));
        for(int i=0;i<=amt;i++){
            if(i%coins[0]==0){
                dp[0][i]=i/coins[0];
            }
            else{
                dp[0][i]=1e9;
            }
        }
        
        for(int i=1;i<n;i++){
            for(int j=0;j<=amt;j++){
                
                int notake = dp[i-1][j];
                int take = INT_MAX;
                if(j>=coins[i]) take = 1+dp[i][j-coins[i]];
                dp[i][j]=min(take, notake);
            }
        }
        if(dp[n-1][amt]>=1e9) return -1;
        return dp[n-1][amt];
    }
};