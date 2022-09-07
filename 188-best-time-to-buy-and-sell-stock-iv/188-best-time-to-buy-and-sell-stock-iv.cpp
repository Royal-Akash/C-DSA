class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
        int n = prices.size();
        int z = 2*k+1;
        vector<vector<int>>dp(n+1 , vector<int>(z , 0));
        int profit=0;
        for(int i=n-1;i>=0;i--){
            for(int j=z-2;j>=0;j--){
                
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