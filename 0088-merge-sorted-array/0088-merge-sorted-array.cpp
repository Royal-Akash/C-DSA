class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        
        
        int j=0, i=0;
        for(int i=0;i<n;i++){
            nums1.pop_back();
        }
        if(nums1.empty()){
            nums1=nums2;
        }
        // else if(n=1){
        //     if(nums1[0]>=nums2[0]){
        //         nums1.insert(nums1.begin()+i, nums2[0])
        //     }
        //     else{
        //         nums1.push_back(nums2[0]);
        //     }
        // }
        else{
            while(i<=m+n-1 && j<=n-1){

                if(nums1[i]>=nums2[j]){
                    nums1.insert(nums1.begin()+i, nums2[j]);
                    j++;
                }
                else{
                    i++;
                }
            }
            if(j<=n-1){
                while(j<=n-1){
                    nums1.push_back(nums2[j]);
                    j++;
                }
            }
        }
        
    }
};