class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.size();
        int i=0;
        for(int i=0;i<n;i++){
            
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
            st.push(s[i]);
            }
            
            else{
                
                if(s[i]==')' && !st.empty() && st.top()=='(') st.pop();
                else if(s[i]=='}' && !st.empty() && st.top() =='{') st.pop();
                else if(s[i]==']' && !st.empty() && st.top() =='[') st.pop();
                else{
                return false; }
            }
        }
        return st.empty();
    }
};