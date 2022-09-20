class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        // st.push(nums[n-1]);
        int te = INT_MIN;
        for(int i=n-1;i>=0;i--){
            
         if(nums[i]<te) return true;
            while(!st.empty() && st.top()<nums[i]){
                
                te=st.top();
                st.pop();
                
            }
            st.push(nums[i]);
        }
        return false;
    }
};