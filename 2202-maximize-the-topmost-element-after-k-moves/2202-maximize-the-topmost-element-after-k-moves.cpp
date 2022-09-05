// class Solution {
// public:
//     int maximumTop(vector<int>& nums, int k) {
//         int maxi=INT_MIN;
        
//         if(nums.size()<=1) return -1;
// //         if((nums.size()-k)<=0) return -1;
//         // k=k%nums.size();
//         if(k>nums.size()){
//             for(int i=0;i<nums.size();i++){
//                  maxi=max(maxi , nums[i]);
//             }
//         }
//         else{
//             for(int i=0;i<=k;i++){
//                  maxi=max(maxi , nums[i]);
//             }
//         }
//         return maxi;
//     }
// };

class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        if(k%2!=0 && nums.size()==1) return -1;
        int maxi=INT_MIN;
        for(int i=0;i<k-1 && i<nums.size();i++) maxi=max(maxi,nums[i]);
        if(k<nums.size()) maxi=max(maxi,nums[k]);
        return maxi;
    }
};