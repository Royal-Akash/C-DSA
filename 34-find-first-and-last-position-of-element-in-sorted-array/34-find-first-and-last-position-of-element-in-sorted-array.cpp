class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v;
        int min = -1 , max = -1;
        int e = nums.size()-1 , s=0 ;
        while(s<=e){
        
        int mid = s+(e-s)/2;
        
        if(nums[mid]>target){
            e=mid-1;
        }
        else if(nums[mid]<target){
            s=mid+1;
        }
        else if(nums[mid]==target){
            e=mid-1;
            min=mid;
        }
           
        }
        v.push_back(min);
        e = nums.size()-1 , s=0 ;

        while(s<=e){
        
        int mid = s+(e-s)/2;
        
        if(nums[mid]>target){
            e=mid-1;
        }
        else if(nums[mid]<target){
            s=mid+1;
        }
        else if(nums[mid]==target){
            max=mid;
            s=mid+1;
            
        }
           
        }
        v.push_back(max);
        return v;
    }
};