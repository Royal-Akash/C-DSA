class Solution {
public:
    int uniquePaths(int m, int n) {
        
//         int dp[m][n];
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(i==0 || j==0) dp[i][j]=1;
//                 else{
//                     int up = 0;
//                     int left = 0;
//                     if(j>0) up=dp[i][j-1];
//                     if(i>0) left = dp[i-1][j];

//                     dp[i][j]=up+left;
//                 }
//             }
//         }
//         return dp[m-1][n-1];
        
        vector<int>prev(n, 0);
        for(int i=0;i<m;i++){
            vector<int>curr(n, 0);
            for(int j=0;j<n;j++){
                
                if(i==0 || j==0) curr[j]=1;
                else{
                    int up = 0, left = 0;
                    if(i>0) up = prev[j];
                    if(j>0) left = curr[j-1];
                    
                    curr[j]=up+left;
                    
                }
            }
            prev= curr;
        }
        return prev[n-1];
    }
};