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
        vector<int>prev(amt+1, 0), curr(amt+1, 0);
        for(int i=0;i<=amt;i++){
            if(i%coins[0]==0){
                prev[i]=i/coins[0];
            }
            else{
                prev[i]=1e9;
            }
        }
        
        for(int i=1;i<n;i++){
            for(int j=0;j<=amt;j++){
                
                int notake = prev[j];
                int take = INT_MAX;
                if(j>=coins[i]) take = 1+curr[j-coins[i]];
                curr[j]=min(take, notake);
            }
            prev=curr;
        }
        if(prev[amt]>=1e9) return -1;
        return prev[amt];
    }
};