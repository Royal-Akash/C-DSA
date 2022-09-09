class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        map<int , int>mp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        int count=0;
        for(auto it: mp){
            int x = it.second;
            count+=(x*(x-1))/2;
        }
        return count;
    }
};