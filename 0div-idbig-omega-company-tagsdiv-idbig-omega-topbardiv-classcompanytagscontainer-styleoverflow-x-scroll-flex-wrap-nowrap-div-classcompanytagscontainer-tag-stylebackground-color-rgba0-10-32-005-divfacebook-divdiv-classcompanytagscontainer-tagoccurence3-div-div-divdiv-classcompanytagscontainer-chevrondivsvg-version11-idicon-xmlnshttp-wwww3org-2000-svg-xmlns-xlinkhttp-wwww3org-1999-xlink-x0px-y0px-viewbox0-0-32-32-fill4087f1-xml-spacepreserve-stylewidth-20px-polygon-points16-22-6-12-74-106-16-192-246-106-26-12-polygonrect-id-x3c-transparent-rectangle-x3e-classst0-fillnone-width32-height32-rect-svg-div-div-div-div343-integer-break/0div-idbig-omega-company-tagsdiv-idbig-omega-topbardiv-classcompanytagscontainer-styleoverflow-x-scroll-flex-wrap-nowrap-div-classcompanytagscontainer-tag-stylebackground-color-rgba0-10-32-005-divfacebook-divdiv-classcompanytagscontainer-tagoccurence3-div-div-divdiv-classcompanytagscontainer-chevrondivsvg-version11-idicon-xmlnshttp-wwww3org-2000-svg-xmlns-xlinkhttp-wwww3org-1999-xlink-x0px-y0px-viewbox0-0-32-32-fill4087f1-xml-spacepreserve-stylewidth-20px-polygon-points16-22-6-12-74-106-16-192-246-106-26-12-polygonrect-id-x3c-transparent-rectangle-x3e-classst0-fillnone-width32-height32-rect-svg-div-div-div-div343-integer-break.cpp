class Solution {
public:

    int sol(int num, vector<int>&dp){
        if(num < 2 )return 1;

        //IMPORTANT OBSERVATION POINT! Remember?
        if(dp[num] != -1) return max(num , dp[num]);

        int res = 1;

        //checking all states
        //For num = 4
        // i = 1, res = max(res , sol(1, dp) , sol(3,dp));
        // i = 2, res = max(res , sol(2,dp), sol(2, dp))
        //refer diagrams for a better understanding
        for(int i = 1; i < num ; i ++){
            res = max(res , sol(i , dp) * sol(num - i , dp));
        }

        //storing in dp and returning 
        return dp[num] = res;
    }

    int integerBreak(int n) {

        if(n <= 2)return 1;
        
        vector<int>dp(n + 1, -1);
        dp[2] = 1;
        
        int ans = sol(n , dp);
        return ans;
    }
};