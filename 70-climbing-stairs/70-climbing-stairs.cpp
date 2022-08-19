class Solution {
public:
    int climbStairs(int n) {
        
        // vector<int> dp;
        // dp.push_back(0);
        // dp.push_back(1);
        // dp.push_back(2);
        // for(int i=3;i<=n;i++){
        //     int y= dp[i-1]+dp[i-2];
        //     dp.push_back(y);
        // }
        // return dp[n];
        
        int dp[n+1][n+1];
        
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        for(int i=0;i<=n;i++){
            dp[0][i]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                
                if(i>2 && j>2){
                    dp[i][j]=dp[i-1][j-1]+dp[i-2][j-2];
                }
                else{
                    dp[i][j]=i;
                }
                
                
           }
        }
        return dp[n][n];
        
    }
};