class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>>dp(n, vector<int>(n, 0));
        for(int i=0;i<n;i++){
            dp[0][i]=matrix[0][i];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                
                int top=INT_MAX, left=INT_MAX, right=INT_MAX;
                if(i>0) top=dp[i-1][j] + matrix[i][j];
                if(i>0 && j<n-1) right=dp[i-1][j+1]+matrix[i][j];
                if(i>0 && j>0) left=dp[i-1][j-1]+matrix[i][j];
                
                dp[i][j]=min(top, min(left, right));
                
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            ans = min(ans, dp[n-1][i]);
        }
        return ans;
    }
};