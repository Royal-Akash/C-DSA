class Solution {
public:
    int find(int n , int m , string & word1 , string & word2 , vector<vector<int>> &dp){
        
        if(n<0) return m+1;
        if(m<0) return n+1;
        
        if(dp[n][m]!=-1) return dp[n][m];
        
        if(word1[n]==word2[m]){
        return dp[n][m]=find(n-1 , m-1 , word1 , word2 , dp);
        }
        
        else return dp[n][m]=1+min(find(n-1 , m-1 , word1 , word2 , dp)
                ,min(find(n , m-1 , word1 , word2 , dp) ,find(n-1 , m , word1 , word2 , dp)));
        
    }
    
//             int editDistanceUtil(string& S1, string& S2, int i, int j, vector<vector<int>>& dp){

//             if(i<0)
//                 return j+1;
//             if(j<0)
//                 return i+1;

//             if(dp[i][j]!=-1) return dp[i][j];

//             if(S1[i]==S2[j])
//                 return dp[i][j] =  0+editDistanceUtil(S1,S2,i-1,j-1,dp);

//             // Minimum of three choices
//             else return dp[i][j] = 1+min(editDistanceUtil(S1,S2,i-1,j-1,dp),
//             min(editDistanceUtil(S1,S2,i-1,j,dp),editDistanceUtil(S1,S2,i,j-1,dp)));

//         }
    
    
    int minDistance(string word1, string word2) {
        
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>>dp(n , vector<int>(m , -1));
        return find(n-1 , m-1 , word1, word2 , dp);
          
//             int n = S1.size();
//             int m = S2.size();

//             vector<vector<int>> dp(n,vector<int>(m,-1));
//             return editDistanceUtil(S1,S2,n-1,m-1,dp);
    }
};