class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        auto ans =0 , sum=0;
        vector<int> num;
        for(int i=0;i<nums.size();i++){
            ans = nums[i];
            sum = target-ans;
           auto total = find(nums.begin()+i+1 , nums.end() , sum);
            if(total!=nums.end()){
                num.push_back(i);
                num.push_back(total-nums.begin());
                break;
            }
            else{
                continue;
            }
            // cout<<sum<<endl;
        }
         
        return num;
    }
};