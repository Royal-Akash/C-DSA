class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int n = nums.size();
        int i=0, j = n-1;
        int n1 = -1, n2=-1;
        while(i<=j){
            int mid = i+(j-i)/2;
            if(nums[mid]>target){
                j=mid-1;
            }
            if(nums[mid]<target){
                i=mid+1;
            }
            if(nums[mid]==target){
                j=mid-1;
                n1=mid;
            }
        }
        i=0, j = n-1;
        while(i<=j){
            int mid = i+(j-i)/2;
            if(nums[mid]>target){
                j=mid-1;
            }
            if(nums[mid]<target){
                i=mid+1;
            }
            if(nums[mid]==target){
                i=mid+1;
                n2=mid;
            }
        }
        return {n1, n2};
    }
};