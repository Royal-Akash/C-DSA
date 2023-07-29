class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int k = nums1.size()+nums2.size();
        double ans = 0;
        int count=0;
        bool flag = false;
        if(k%2==0) flag = true;
//         int i=0, j=0;
//         int num1=0;
//         while(count!=k/2 || count!=k/2+1){
            
//             if(flag==true && ((count==k/2 ) || (count==k/2+1))){
//                 ans+=num1;
//                 if(count==k/2+1){
//                     break;
//                 }
//             }
//             if(flag==false && count==k/2){
//                 ans+=num1;
//                 break;
//             }
            
//             if(nums1[i]<nums2[j] && i<=nums1.size()-1){
//                 count++;
//                 num1=nums1[i];
//                 i++;
//             }
//             else if(nums1[i]>nums2[j] && j<=nums2.size()-1){
//                 count++;
//                 num1=nums2[j];
//                 j++;
//             }
//             else if(i==nums1.size()-1 && j<=nums2.size()-1){
//                 count++;
//                 num1=nums2[j];
//                 j++;
//             }
//             else{
//                 count++;
//                 num1=nums1[i];
//                 i++;
//             }
            
//         }
//         if(flag==true) return ans/2;
        
//         return ans;
        int m = nums1.size();
        int n = nums2.size();
        int total = m + n;
        int i = 0, j = 0;
        int prev = 0, curr = 0;

        for (int count = 0; count <= k / 2; count++) {
            prev = curr;
            if (i < m && (j >= n || nums1[i] < nums2[j])) {
                curr = nums1[i];
                i++;
            } else {
                curr = nums2[j];
                j++;
            }
        }

        if (total % 2 == 0) {
            return (prev + curr) / 2.0;
        } else {
            return curr;
        }
        
    }
};