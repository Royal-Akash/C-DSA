class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        if(nums.size()==1) return nums[0];
        int n = nums.size();
        for(int i=1;i<n;i++){
            if(nums[i-1]==nums[i]){
                i++;
            }
            else{
                return nums[i-1];
            }
        }
        return nums[n-1];
    }
};