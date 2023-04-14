class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string rev = s;
        reverse(s.begin(), s.end());
        
        int size = s.size();
        int dp[size + 1][size + 1];
        
        for(int i = 0; i < size + 1; ++i)
            dp[0][i] = dp[i][0] = 0;

        
        for(int i = 1; i < size + 1; ++i)
            for(int j = 1; j < size + 1; ++j)
                if(s[i - 1] == rev[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

        
        return dp[size][size];
    }
};