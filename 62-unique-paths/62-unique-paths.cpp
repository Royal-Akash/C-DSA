class Solution {
public:
    int countways(vector<vector<int>>& dp , int m , int n){
        
        for(int i=0;i<m;i++){
                    dp[i][0]=1;
                
        }
        
            for(int j=0;j<n;j++){
                    dp[0][j]=1;
                
            }
        
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
                
            }
        }
        
        return dp[m-1][n-1];
    }
    
    
    int uniquePaths(int m, int n) {
        
        vector<vector<int>>dp(m , vector<int>(n , -1));
        return countways(dp , m , n);   
        
    }
};





//         m-- , n--;
//         if(n<m){
//             swap(n ,m);
//         }
        
//         double paths = 1.0;
//         for(int i=1;i<=n;i++){
//             paths = paths*(m+i)/i;
//         } 
        ///////////////////////////////////////////////
        
//         int N = n+m-2;
//         int R = m-1;
        
//         double path = 1;
//         for(int i=1;i<=R;i++){
            
//             path = path * (N-R+i)/i;
            
//         }
        
//         return path;
        
//         ////////////////////////////////////////////