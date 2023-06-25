class Solution {
private:
    const int MOD = 1e9 + 7;

public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        vector<vector<int>> dp(n, vector<int>(fuel + 1, 0));

        // Base case: If start and finish are the same city, we have 1 possible route
        dp[start][fuel] = 1;

        for (int f = fuel; f >= 0; f--) {
            for (int cur = 0; cur < n; cur++) {
                for (int next = 0; next < n; next++) {
                    if (next != cur) {
                        int cost = abs(locations[cur] - locations[next]);
                        if (f + cost <= fuel) {
                            dp[next][f] = (dp[next][f] + dp[cur][f + cost]) % MOD;
                        }
                    }
                }
            }
        }

        int count = 0;
        for (int f = 0; f <= fuel; f++) {
            count = (count + dp[finish][f]) % MOD;
        }

        return count;
    }
};
