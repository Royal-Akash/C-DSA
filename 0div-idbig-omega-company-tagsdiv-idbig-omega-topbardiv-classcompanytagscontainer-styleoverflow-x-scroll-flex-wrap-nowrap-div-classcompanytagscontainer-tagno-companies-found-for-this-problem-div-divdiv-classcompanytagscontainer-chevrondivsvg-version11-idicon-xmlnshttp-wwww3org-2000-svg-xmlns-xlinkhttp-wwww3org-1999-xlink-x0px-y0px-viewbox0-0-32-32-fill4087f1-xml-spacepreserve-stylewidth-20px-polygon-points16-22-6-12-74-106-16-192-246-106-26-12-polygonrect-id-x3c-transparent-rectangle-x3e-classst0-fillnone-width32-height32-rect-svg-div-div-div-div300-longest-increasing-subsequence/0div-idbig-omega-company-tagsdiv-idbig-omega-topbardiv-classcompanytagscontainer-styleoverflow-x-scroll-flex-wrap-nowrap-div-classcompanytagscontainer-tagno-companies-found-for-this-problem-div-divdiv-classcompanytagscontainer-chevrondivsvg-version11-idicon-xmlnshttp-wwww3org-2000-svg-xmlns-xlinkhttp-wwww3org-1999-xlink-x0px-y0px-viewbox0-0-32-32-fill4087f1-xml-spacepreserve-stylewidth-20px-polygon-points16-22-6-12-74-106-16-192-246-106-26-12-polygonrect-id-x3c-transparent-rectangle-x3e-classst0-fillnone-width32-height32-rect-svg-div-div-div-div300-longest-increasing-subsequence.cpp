class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();  
//         if(n==1) return 1;
//         int maxi = 0;
//         vector<int>dp(n, 1);
//         for(int i=1;i<n;i++){
//             for(int j=0;j<i;j++){
                
//                 if(nums[i]>nums[j]){
//                     dp[i]=max(dp[i], 1+dp[j]);
//                 }
//             }
//             maxi=max(maxi, dp[i]);
//         }
        
//         return maxi;
        
        vector<int>temp;
        temp.push_back(nums[0]);
        for(int i=1;i<n;i++){
            
            if(nums[i]>temp.back()){
                temp.push_back(nums[i]);
            }
            else{
                int ind = lower_bound(temp.begin(), temp.end(), nums[i])-temp.begin();
                temp[ind]=nums[i];
            }
            
        }
        return temp.size();
    }
};