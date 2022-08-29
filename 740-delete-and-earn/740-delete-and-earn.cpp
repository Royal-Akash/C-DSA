class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        vector<int>v(10005 , 0);
            for(auto it : nums){
                v[it]+=it;
            }
        
        vector<int> dp(10005);
        dp[0]=v[0];
        dp[1]=v[1];
        
        for(int i=2;i<v.size();i++){
            dp[i]=max(dp[i-2]+v[i] , dp[i-1]);
            
        }
        return dp[10000];
    }
};