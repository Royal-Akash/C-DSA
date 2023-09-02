class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        
        unordered_map<int, int>mp;
        long long sum  = 0;
        long long maxi = 0;
        int j = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(i<k){
                sum+=1ll*nums[i];
                mp[nums[i]]++;
                if(mp.size()>=m){
                    maxi = max(maxi, sum);
                }
            }
            else{
                
                sum-=1ll*nums[j];
                sum+=1ll*nums[i];
                
                mp[nums[j]]--;
                mp[nums[i]]++;
                if(mp[nums[j]]<=0) mp.erase(nums[j]);
                j++;
                if(mp.size()>=m){
                    maxi = max(maxi, sum);
                }
                
            }
        }
        return maxi;
        
    }
};