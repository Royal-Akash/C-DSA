class Solution {
public:
    long long mostPoints(vector<vector<int>>& q) {
        long long n = q.size();
        vector<long long> dp(n , -1);
        return find(0 , dp , q);
        
    }
    
    long long find(long long i , vector<long long> &dp ,vector<vector<int>>& q){
        long long n = q.size();
        if(i>=n){
            return 0;
        }
        
        if(dp[i]!=-1){
            return dp[i];
        }
        
        long curr = q[i][0]+find(i+q[i][1]+1 , dp , q);
        long next = find(i+1 , dp , q);
        return dp[i]=max(curr , next);
        
        // return dp[n-1];
    }
    
};