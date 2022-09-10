class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector<vector<int>>dp(n+2 , vector<int>(2 , 0));
        int profit=0;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                
                if(j==0){
                    profit=max(-prices[i]+dp[i+1][1] , dp[i+1][0]);
                }
                if(j==1){
                    profit=max(prices[i]+dp[i+2][0] , dp[i+1][1]);
                }
                dp[i][j]=profit;
            }
        }
        return dp[0][0];
    }
};