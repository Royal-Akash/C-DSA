class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        int n = nums.size();
        vector<int>dp(n, 1), hash(n);
        sort(nums.begin(), nums.end());
        int maxi = 1,lastInd=0;
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[i]<1+dp[j]){
                    dp[i]=1+dp[j];
                    hash[i]=j;
                }
            }
            if(maxi<dp[i]){
                maxi=dp[i];
                lastInd=i;
            }
        }
        
        vector<int>temp;
        temp.push_back(nums[lastInd]);
        while(hash[lastInd]!=lastInd){
            
            lastInd=hash[lastInd];
            temp.push_back(nums[lastInd]);
            
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }
};