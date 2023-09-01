class Solution {
public:
    int find(vector<int>& temp, vector<int>&dp){
        
        int n = temp.size();
        dp[0]=temp[0];
        for(int i=1;i<n;i++){
            
            int pick = temp[i];
            if(i>1){
                pick+=dp[i-2];
            }
            int notpick = dp[i-1];
            
            dp[i]=max(pick , notpick);
            
        }
        return dp[n-1];
        
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0], nums[1]);
        vector<int>temp1, temp2;
        for(int i=0;i<n;i++){
            if(i!=0){
                temp1.push_back(nums[i]);
            }
            if(i!=n-1){
                temp2.push_back(nums[i]);
            }
        }
        vector<int>dp(n-1, 0);
        // vector<int>dp2(n-1, 0);
        int sum1 = find(temp1, dp);
        int sum2 = find(temp2, dp);
        return max(sum1 , sum2);
    }
};