class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        
        // int n;
        // cin>>n;
        int count=0;
        // int array[n];
        vector<int> v;
        for(int i =0; i<nums.size();i++)
        {
            count+=nums[i];
            v.push_back(count);
        }
        
        return v;
    }
};