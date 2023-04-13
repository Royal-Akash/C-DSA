class Solution {
public:
    bool validateStackSequences(vector<int>& push1, vector<int>& pop1) {
        stack<int>st;
        int j=0;
        for(int i=0;i<push1.size();i++){
        
            st.push(push1[i]);
            while(!st.empty() && st.top()==pop1[j]){
                j++;
                st.pop();
            }
            
        }
        if(st.empty()) return true;
        
        return false;
    }
};