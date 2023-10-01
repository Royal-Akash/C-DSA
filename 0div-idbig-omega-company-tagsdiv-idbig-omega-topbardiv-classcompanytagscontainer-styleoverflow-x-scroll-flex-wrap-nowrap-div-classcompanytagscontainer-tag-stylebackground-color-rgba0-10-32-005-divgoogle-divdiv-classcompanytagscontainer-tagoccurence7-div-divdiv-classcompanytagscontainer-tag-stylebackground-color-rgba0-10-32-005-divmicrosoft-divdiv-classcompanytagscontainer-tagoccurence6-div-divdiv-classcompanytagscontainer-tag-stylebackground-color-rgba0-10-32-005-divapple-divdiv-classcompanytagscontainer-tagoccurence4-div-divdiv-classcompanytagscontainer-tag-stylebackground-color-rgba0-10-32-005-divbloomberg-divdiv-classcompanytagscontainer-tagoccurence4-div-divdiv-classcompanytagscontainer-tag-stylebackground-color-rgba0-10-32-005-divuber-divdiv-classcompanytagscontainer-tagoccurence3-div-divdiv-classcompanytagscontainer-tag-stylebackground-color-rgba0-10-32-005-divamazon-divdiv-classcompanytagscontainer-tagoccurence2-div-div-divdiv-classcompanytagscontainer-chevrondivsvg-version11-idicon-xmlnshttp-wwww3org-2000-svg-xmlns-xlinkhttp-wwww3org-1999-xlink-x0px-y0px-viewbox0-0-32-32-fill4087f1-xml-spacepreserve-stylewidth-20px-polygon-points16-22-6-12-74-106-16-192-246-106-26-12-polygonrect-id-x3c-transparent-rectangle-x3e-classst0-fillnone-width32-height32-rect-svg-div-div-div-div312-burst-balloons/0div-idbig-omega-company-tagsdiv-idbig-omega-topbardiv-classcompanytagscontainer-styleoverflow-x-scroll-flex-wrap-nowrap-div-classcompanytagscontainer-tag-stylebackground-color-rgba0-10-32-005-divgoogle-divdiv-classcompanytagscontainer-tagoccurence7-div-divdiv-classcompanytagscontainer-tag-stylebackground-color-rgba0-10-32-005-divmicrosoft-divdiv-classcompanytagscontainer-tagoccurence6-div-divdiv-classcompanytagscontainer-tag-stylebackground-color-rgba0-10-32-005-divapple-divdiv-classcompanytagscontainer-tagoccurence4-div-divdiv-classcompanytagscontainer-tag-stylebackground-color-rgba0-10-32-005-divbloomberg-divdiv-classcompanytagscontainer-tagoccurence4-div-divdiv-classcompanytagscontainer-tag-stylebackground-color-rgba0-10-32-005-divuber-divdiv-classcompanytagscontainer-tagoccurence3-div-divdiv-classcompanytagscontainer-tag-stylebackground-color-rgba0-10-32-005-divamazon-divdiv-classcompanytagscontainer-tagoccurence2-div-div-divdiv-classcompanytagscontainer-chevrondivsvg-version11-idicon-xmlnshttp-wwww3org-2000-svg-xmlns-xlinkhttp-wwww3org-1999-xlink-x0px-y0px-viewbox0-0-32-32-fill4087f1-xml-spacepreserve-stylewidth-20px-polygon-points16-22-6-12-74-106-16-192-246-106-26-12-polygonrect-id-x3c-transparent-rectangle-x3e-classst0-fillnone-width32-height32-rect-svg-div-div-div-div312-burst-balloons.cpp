class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int cs = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        vector<vector<int>>dp(cs+2, vector<int>(cs+2, 0));
        
        for(int i=cs;i>=1;i--){
            
            for(int j=1;j<=cs;j++){
                
                if(i>j) continue;
                
                int mini = INT_MIN;
                
                for(int k=i;k<=j;k++){
                    
                    int cost = nums[j+1]*nums[k]*nums[i-1] + dp[i][k-1]+dp[k+1][j];
                    mini =max(mini, cost);
                }
                dp[i][j]=mini;
            }
            
        }
        return dp[1][cs];
    }
};