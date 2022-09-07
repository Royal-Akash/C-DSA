class Solution {
public:
    int maxProfit(int a, vector<int>& prices) {
        
        int n = prices.size();
        // int z = 2*k+1;
//         vector<vector<int>>dp(n+1 , vector<int>(z , 0));
//         int profit=0;
//         for(int i=n-1;i>=0;i--){
//             for(int j=z-2;j>=0;j--){
                
//                 if(j%2==0){
//                     profit=max(-prices[i]+dp[i+1][j+1] , dp[i+1][j]);
//                 }
//                 else{
//                     profit=max(prices[i]+dp[i+1][j+1] , dp[i+1][j]);
//                 }
//                 dp[i][j]=profit;
//             }
//         }
//         return dp[0][0];
        
        vector<vector<vector<int>>> dp(n+1 , vector<vector<int>>(2 , vector<int>(a+1, 0)));
        
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                for(int k=1;k<=a;k++){
                    
                    if(j==0){
                        dp[i][j][k]=max(-prices[i]+dp[i+1][1][k] , dp[i+1][0][k]);
                    }
                    else{
                        dp[i][j][k]=max(prices[i]+dp[i+1][0][k-1] , dp[i+1][1][k]);
                    }
                    
                }
            }
        }
       return dp[0][0][a];
        
    }
};