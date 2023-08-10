class Solution {
public:
    string reverseWords(string s) {
        
        stack<string>st;
        string temp;
        for(int i=0;i<s.length();i++){
            if(s[i]==' ' && temp!=""){
                st.push(temp);
                temp="";
            }
            else if(s[i]!=' '){
                temp+=s[i];
            }
            else{
                continue;
            }
        }
        if(temp!=" ") st.push(temp);
        string ans;
        while(!st.empty()){
            if(ans=="" && st.top()!=""){
                ans+=st.top();
            }
            else if(st.top()!=""){
                ans=ans+" "+st.top();
            }
            st.pop();
        }
        return ans;
    }
};