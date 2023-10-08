class Solution {
public:
    int N, M, K;
    int mod = 1e9+7;
    int dp[51][51][101];
    int solve(int idx, int search, int maxi){
        
        if(idx==N){
            if(search==K) return 1;
            return 0;
        }
        if(dp[idx][search][maxi]!=-1) return dp[idx][search][maxi];
        int result = 0;
        for(int i=1;i<=M;i++){
            
            if(i>maxi){
                result= (result+solve(idx+1, search+1, i))%mod;
            }
            else{
                result= (result + solve(idx+1, search, maxi))%mod;
            }
        }
        
        return dp[idx][search][maxi]=result%mod;
        
    }
    int numOfArrays(int n, int m, int k) {
        N=n;
        M=m;
        K=k;
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0);
        
    }
};