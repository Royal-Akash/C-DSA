class Solution {
public:
    bool isMatch(string s, string p) {
        
//         int n = p.size();
//         int m = s.size();
        
//         vector<vector<bool>>dp(n+1, vector<bool>(m+1, 0));
        
//         // Both exhausted
//         dp[0][0]=true;
        
//         // p = exhausted but string doesn't
        
//         // for(int i=1;i<=m;i++){
//         //     dp[0][i]=false;
//         // }
        
//         // p doesn't but s exhauted
        
//         for(int i=1;i<=n;i++){
//             if(p[i-1]=='*'){
//                 dp[i][0]=dp[i-2][0];
//             }
//             else{
//                 dp[i][0]=false;
//             }
            
//         }
        
//         for(int i=1;i<=n;i++){
//             for(int j=1;j<=m;j++){
                
//                 if(p[i-1]=='.' || p[i-1]==s[j-1]){
//                     dp[i][j]=dp[i-1][j-1];
//                 }
//                 else if(p[i-1]=='*'){
//                     dp[i][j]= dp[i-2][j];
//                     if(p[i-2]==s[i-1] || p[i-2]=='.'){
//                         dp[i][j]=dp[i][j] || dp[i][j-1];
//                     }
//                 }
//             }
//         }
        
//         return dp[n][m];
        
        
    int m=s.length();
    int n=p.length();
    
    vector<vector<bool>>dp(m+1,vector<bool>(n+1,false));
    
    dp[0][0]=true;
    
    for(int j=1;j<=n;j++){
        
        if(p[j-1]=='*'){
            dp[0][j]=dp[0][j-2];
        }
        
        else{
            dp[0][j]=false;
        }
        
    }
    
    
    for(int i=1;i<=m;i++){
        
        for(int j=1;j<=n;j++){
            
            if(s[i-1]==p[j-1] || p[j-1]=='.'){
                dp[i][j]=dp[i-1][j-1];
            }
            
            else if(p[j-1]=='*'){
                
                dp[i][j]=dp[i][j-2];
                
                if(s[i-1]==p[j-2] || p[j-2]=='.'){
                    dp[i][j]=dp[i][j] || dp[i-1][j];
                }
                
            }
            
        }
        
    }
    
    return dp[m][n];
    }
};