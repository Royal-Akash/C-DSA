class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        
        int cs = cuts.size();
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>>dp(cs+2, vector<int>(cs+2, 0));
        
        for(int i=cs;i>=1;i--){
            
            for(int j=1;j<=cs;j++){
                
                if(i>j) continue;
                
                int mini = INT_MAX;
                
                for(int k=i;k<=j;k++){
                    
                    int cost = cuts[j+1]-cuts[i-1] + dp[i][k-1]+dp[k+1][j];
                    mini =min(mini, cost);
                }
                dp[i][j]=mini;
            }
            
        }
        return dp[1][cs];
        
    }
};