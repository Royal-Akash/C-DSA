class Solution {
public:
    int fib(int n) {
        
//        int prev=0 , curr=1 , sum=0;
        
//         if(n==0 || n==1) return n;
//         for(int i=1;i<n;i++){
//             sum=prev+curr;
//             prev=curr;
//             curr=sum;
//         }
//         return sum;
        
        int dp[n+1][n+1];
        
        for(int i=0;i<=n;i++){
            dp[0][i]=0;
        }
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                
                if(i>1 && j>1){
                dp[i][j]=dp[i-1][j-1] + dp[i-2][j-2];
                }
                else{
                    dp[i][j]=dp[i-1][j-1]+1;
                }
            }
        }
        return dp[n][n];
    }
};