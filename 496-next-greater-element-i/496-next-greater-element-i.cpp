class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums2.size();
        int m = nums1.size();
        // vector<int>ans;
        unordered_map<int , int>nxt;
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            
            while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
            }
            if(!st.empty()){
                nxt[nums2[i]]=st.top();
            }
            else{
                nxt[nums2[i]]=-1;
            }
            st.push(nums2[i]);
        }
        for(int i=0;i<m;i++){
            nums1[i]=nxt[nums1[i]];
        }
        return nums1;
    }
};