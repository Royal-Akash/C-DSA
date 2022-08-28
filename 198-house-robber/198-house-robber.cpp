class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
//         int dp[n];
//         dp[0]=nums[0];
//         for(int i=1;i<n;i++){
            
//             int pick = nums[i];
//             if(i>1){
//                 pick+=dp[i-2];
//             }
//             int nopick=dp[i-1];
//             dp[i]=max(pick , nopick);
//         }
        
//         return dp[n-1];
        
//         /////////////////// Optimise space /////////////////////////
        
        int prev = nums[0];
        int prev2=0;
        
        for(int i=1;i<n;i++){
            
            int pick = nums[i];
            if(i>1){
                pick+=prev2;
            }
            int nopick=prev;
            int curr = max(pick , nopick);
            prev2=prev;
            prev=curr;
            
        }
        return prev;
    }
};