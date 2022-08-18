class Solution {
public:
    int tribonacci(int n) {
        // int n = m+1;
        int dp[n+1][n+1];
        
        for(int i=0;i<=n;i++){
            dp[0][i]=0;
        }
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                
                if(i>2 && j>2){
                dp[i][j]=dp[i-1][j-1] + dp[i-2][j-2] + dp[i-3][j-3];
                }
                else{
                    dp[i][j]=1;
                }
            }
        }
        return dp[n][n];
    }
};