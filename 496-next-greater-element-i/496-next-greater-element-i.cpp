class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums2.size();
        int m = nums1.size();
        vector<int>ans;
        unordered_map<int , int>nxt;
        
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                
                if(nums2[i]<nums2[j]){
                    nxt[nums2[i]]=nums2[j];
                    break;
                }
                else{
                    nxt[nums2[i]]=-1;
                }
            }
        }
        nxt[nums2[n-1]]=-1;
        for(int i=0;i<m;i++){
            ans.push_back(nxt[nums1[i]]);
        }
        return ans;
    }
};