class Solution {
public:
    int findLength(vector<int>& n1, vector<int>& n2) {
        
        int m = n1.size();
        int n = n2.size();
        
        int dp[m+1][n+1];
        
        for(int i=0;i<=m;i++){
            dp[i][0]=0;
        }
        for(int i=0;i<=n;i++){
            dp[0][i]=0;
        }
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                
                if(n1[i-1]==n2[j-1]){
                    dp[i][j]= 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=0;
                }
                
            }
        }
        
        int maxi =0;
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                maxi= max(maxi , dp[i][j]);
            }
        }
        
        return maxi;
    }
};