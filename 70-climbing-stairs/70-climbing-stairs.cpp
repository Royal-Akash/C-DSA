class Solution {
public:
    int climbStairs(int n) {
        
        vector<int> dp;
        dp.push_back(0);
        dp.push_back(1);
        dp.push_back(2);
        for(int i=3;i<=n;i++){
            int y= dp[i-1]+dp[i-2];
            dp.push_back(y);
        }
        return dp[n];
    }
};