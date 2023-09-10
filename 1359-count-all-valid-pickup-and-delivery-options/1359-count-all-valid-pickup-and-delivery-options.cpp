class Solution {
public:
    int countOrders(int n) {
        
        // const long long mod = 1e9+7;
        // vector<long long>dp(n+1, 0);
        // dp[1]=1*1ll;
        // dp[2]=6*1ll;
        // for(int i=3;i<=n;i++){
        //     long long sum = (2ll*i-1)*i;
        //     dp[i]=(dp[i-1]*sum)%mod;
        // }
        // return (int)dp[n];
        long long MODULO = 1e9 + 7, ans = 1;
        for (int i = 2; i <= n; i++) {
            int spaceNum = (i-1)*2 + 1;
            ans *= spaceNum * (spaceNum + 1) / 2;
            ans %= MODULO;
        }
        return (int) ans;
    }
};