class Solution {
public:
    int mod = (int)(1e9+7);
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        
        vector<vector<int>> dp(n , vector<int>(m , -1));
        
//         for(int i=0;i<n;i++){
//             dp[i][0]=1;
//         }
//         for(int i=0;i<m;i++){
//             dp[0][i]=1;
//         }
        
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(obstacleGrid[i][j]==1){ 
//                     dp[i][j]=0;
//                     continue;
//                 }
//                 else if(i>0 && j>0){
//                 dp[i][j]=dp[i-1][j] + dp[i][j-1];
//                 }
//             }
//         }
//         return dp[n-1][m-1]%mod;
        for(int i=0; i<n ;i++){
      for(int j=0; j<m; j++){
          
          //base conditions
          if(i>=0 && j>=0 && obstacleGrid[i][j]==1){
            dp[i][j]=0;
            continue;
          }
          if(i==0 && j==0){
              dp[i][j]=1;
              continue;
          }
          
          int up=0;
          int left = 0;
          
          if(i>0) 
            up = dp[i-1][j];
          if(j>0)
            left = dp[i][j-1];
            
          dp[i][j] = up+left;
      }
  }
  
  return dp[n-1][m-1];
    }
};