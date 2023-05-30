class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>sum;
        map<int, int>mp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int a = nums[i];
            int ans = target-a;
            if(mp.find(ans)!=mp.end()){
                return {mp[ans], i};
            }
            mp[a]=i;
            
        }
        return {-1, -1};
        
    }
};