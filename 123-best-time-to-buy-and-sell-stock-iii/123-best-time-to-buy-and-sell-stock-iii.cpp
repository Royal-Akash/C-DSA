class Solution {
public:
    int maxProfit(vector<int>& prices){
       
        int n = prices.size();
//         vector<vector<vector<int>>> dp(n+1 , vector<vector<int>>(2 , vector<int>(3, 0)));
        
//         for(int i=n-1;i>=0;i--){
//             for(int j=0;j<2;j++){
//                 for(int k=1;k<=2;k++){
                    
//                     if(j==0){
//                         dp[i][j][k]=max(-prices[i]+dp[i+1][1][k] , dp[i+1][0][k]);
//                     }
//                     else{
//                         dp[i][j][k]=max(prices[i]+dp[i+1][0][k-1] , dp[i+1][1][k]);
//                     }
                    
//                 }
//             }
//         }
//        return dp[0][0][2];
        
        vector<vector<int>>dp(n+1 , vector<int>(5 , 0));
        int profit=0;
        for(int i=n-1;i>=0;i--){
            for(int j=3;j>=0;j--){
                
                if(j%2==0){
                    profit=max(-prices[i]+dp[i+1][j+1] , dp[i+1][j]);
                }
                else{
                    profit=max(prices[i]+dp[i+1][j+1] , dp[i+1][j]);
                }
                dp[i][j]=profit;
            }
        }
        return dp[0][0];
        
    }
};