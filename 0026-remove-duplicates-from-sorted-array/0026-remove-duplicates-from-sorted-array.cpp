class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        // int i = 0;
        // while(i<nums.size()-1){
        //     if(nums[i]==nums[i+1]){
        //         nums.erase(nums.begin()+i);
        //     }
        //     else{
        //         i++;
        //     }
        // }
        // return nums.size();
        int k = 0;
        for(int i=1;i<nums.size();i++){
            
            if(nums[k]!=nums[i]){
                nums[k+1]=nums[i];
                k++;
            }
            
        }
        return k+1;
    }
};