class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
//         int m = nums1.size();
//         int n = nums2.size();
//         int total = m + n;
//         int i = 0, j = 0;
//         int prev = 0, curr = 0;

//         for (int count = 0; count <= total / 2; count++) {
//             prev = curr;
//             if (i < m && (j >= n || nums1[i] < nums2[j])) {
//                 curr = nums1[i];
//                 i++;
//             } else {
//                 curr = nums2[j];
//                 j++;
//             }
//         }

//         if (total % 2 == 0) {
//             return (prev + curr) / 2.0;
//         } else {
//             return curr;
//         }
        int n1 = nums1.size();
        int n2 = nums2.size();
        if(n2<n1) return findMedianSortedArrays(nums2, nums1);
        int low = 0, high = n1;
        
        while(low<=high){
            int cut1 = low + (high-low)/2;
            int cut2 = (n1+n2+1)/2-cut1;
            
            int left1 = cut1==0 ? INT_MIN : nums1[cut1-1];
            int left2 = cut2==0 ? INT_MIN : nums2[cut2-1];
            
            int right1 = cut1==n1 ? INT_MAX : nums1[cut1];
            int right2 = cut2==n2 ? INT_MAX : nums2[cut2];
            
            if(left1<=right2 && left2 <=right1){
                if((n1+n2)%2==0){
                    return (max(left1, left2)+min(right1, right2))/2.0;
                }
                else{
                    return (max(left1, left2));
                }
            }
            else if(left1>right2){
                high=cut1-1;
            }
            else{
                low=cut1+1;             
            }
        }
        return 0.0;
    }
};