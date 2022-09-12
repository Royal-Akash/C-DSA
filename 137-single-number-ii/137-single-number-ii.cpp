class Solution {
public:
    int singleNumber(vector<int>& nums) {
     ////////////////////////Using Set Bits ///////////////////////////   
        // unsigned int shift=1 , ans=0;
        // for(int i=0;i<32;i++){
        //     int count =0;
        //     for(auto it:nums){
        //         if(it&shift){
        //             count++;
        //         }
        //     }
        //     if(count%3!=0){
        //         ans+=shift;
        //     }
        //     shift<<=1;
        // }
        // return ans;
        
        ///// TC = O(n*32);
        
        ///////////////////////// Sorting Technique ///////////////////////
        int n = nums.size();
        sort(nums.begin() , nums.end());
        int ans=0;
        if(n==1) return nums[n-1];
        if(nums[n-1]!=nums[n-2]) return nums[n-1];
        for(int i=1;i<nums.size();i++){
            
            if(nums[i]==nums[i-1]){
                i+=2;
            }
            else{
                ans= nums[i-1];
                break;
            }
        }
            return ans;
    }
};