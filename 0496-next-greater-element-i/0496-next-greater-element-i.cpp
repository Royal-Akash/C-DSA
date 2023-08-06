class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_map<int, int>mp;
        stack<int>st;
        int n = nums2.size();
        int i=n-1;
        while(i>=0){
            if(st.empty()){
                mp[nums2[i]]=-1;
                st.push(nums2[i]);
                i--;
            }
            else if(st.top()>nums2[i]){
                mp[nums2[i]]=st.top();
                st.push(nums2[i]);
                i--;
            }
            else{
                st.pop();
            }
        }
        vector<int>ans;
        for(int i=0;i<nums1.size();i++){
            ans.push_back(mp[nums1[i]]);
        }
        return ans;
    }
};