const int mod = 1e9 + 7, N = 1010;
class Solution {
    int f[N][N] = {};
public:
    int kInversePairs(int n, int K) {
        // initialize: taking first i number, consisting of 0 inverse pair, only 1 way
        for (int i=0 ; i <= n ; i++) f[i][0] = 1;
        
        long long cur = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= K; j++)
            {
                cur = (f[i][j-1] + f[i-1][j] - (j>=i?f[i-1][j-i]:0)) % mod;
                f[i][j] = cur<0?cur+mod:cur;
            }
        }
        return f[n][K];
    }
};