class Solution {
private:
    int binarysearch(vector<int>& nums , int l , int r , int target){
        
        if(r>=l){
            int mid = l + (r-l)/2;
        
            if(nums[mid]==target){
                return mid;
            }
            if(nums[mid]>target){
                return binarysearch(nums , l , mid-1 , target);
            }
            return binarysearch(nums , mid+1 , r , target);
        }
        return -1;
    }
    
public:
    int search(vector<int>& nums, int target) {
        
        int n = nums.size();
        int ans = binarysearch(nums , 0, n-1 , target);
        return ans;
    }
};