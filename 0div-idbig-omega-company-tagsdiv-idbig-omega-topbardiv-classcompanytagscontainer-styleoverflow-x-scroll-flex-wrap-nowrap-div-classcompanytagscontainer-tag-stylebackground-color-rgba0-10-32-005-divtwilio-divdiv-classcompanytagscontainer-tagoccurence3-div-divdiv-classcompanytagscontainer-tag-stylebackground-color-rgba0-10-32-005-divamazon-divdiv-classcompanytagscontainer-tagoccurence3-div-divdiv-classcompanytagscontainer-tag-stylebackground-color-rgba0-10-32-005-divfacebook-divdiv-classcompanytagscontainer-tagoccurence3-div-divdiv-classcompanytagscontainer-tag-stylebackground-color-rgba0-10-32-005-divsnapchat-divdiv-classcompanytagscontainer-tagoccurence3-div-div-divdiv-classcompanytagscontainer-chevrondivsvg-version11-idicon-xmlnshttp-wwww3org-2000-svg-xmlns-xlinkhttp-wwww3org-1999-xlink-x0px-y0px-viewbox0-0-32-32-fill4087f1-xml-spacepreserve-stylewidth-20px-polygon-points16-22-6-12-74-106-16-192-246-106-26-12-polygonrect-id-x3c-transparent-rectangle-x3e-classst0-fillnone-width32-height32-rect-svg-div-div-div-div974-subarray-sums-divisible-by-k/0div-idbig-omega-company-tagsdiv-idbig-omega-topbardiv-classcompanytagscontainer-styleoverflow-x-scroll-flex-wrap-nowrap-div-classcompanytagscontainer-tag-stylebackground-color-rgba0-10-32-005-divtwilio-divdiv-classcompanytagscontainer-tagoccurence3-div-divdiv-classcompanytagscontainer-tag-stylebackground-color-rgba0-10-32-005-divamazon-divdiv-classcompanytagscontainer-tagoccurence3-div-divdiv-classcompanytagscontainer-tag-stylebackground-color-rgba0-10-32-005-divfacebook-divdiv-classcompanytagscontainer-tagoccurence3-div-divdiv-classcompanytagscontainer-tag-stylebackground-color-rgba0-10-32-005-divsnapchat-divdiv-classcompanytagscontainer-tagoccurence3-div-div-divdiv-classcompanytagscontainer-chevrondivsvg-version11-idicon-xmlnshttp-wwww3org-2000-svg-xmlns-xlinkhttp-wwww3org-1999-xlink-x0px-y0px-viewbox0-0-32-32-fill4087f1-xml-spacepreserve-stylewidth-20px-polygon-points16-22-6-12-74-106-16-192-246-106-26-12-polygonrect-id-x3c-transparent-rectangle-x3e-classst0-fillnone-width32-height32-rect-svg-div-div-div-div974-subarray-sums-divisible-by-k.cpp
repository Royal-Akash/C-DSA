class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        int n = nums.size();
        unordered_map<int, int>mp;
        mp[0]++;
        int count = 0;
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            
            if(mp[(sum%k+k)%k]>0){
                count+=mp[(sum%k+k)%k];
            }
            
            mp[(sum%k+k)%k]++;
            
        }
        return count;
    }
};