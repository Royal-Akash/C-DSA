class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int>arr = nums;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int low = 0, high = n-1;
        int left =0, right=0;
        while(low<=high){
            int sol = nums[low]+nums[high];
            if(sol>target){
                high--;
            }
            if(sol<target){
                low++;
            }
            if(sol == target){
                // return{low, high};
                left = low;
                right = high;
                break;
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(arr[i]==nums[left]){
                ans.push_back(i);
            }
            else if(arr[i]==nums[right]){
                ans.push_back(i);
            }
        }
        return ans;;
        
    }
};