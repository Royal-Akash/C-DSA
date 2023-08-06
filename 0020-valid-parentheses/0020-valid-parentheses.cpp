class Solution {
public:
    bool isValid(string s) {
        stack<char>s1;
        int n = s.size();
        // s1.push(s[n-1]);
        for(int i=n-1;i>=0;i--){
            
            if(s1.empty()){
                s1.push(s[i]);
            }
            else if(s[i]=='(' && s1.top()==')'){
                s1.pop();
            }
            else if(s[i]=='[' && s1.top()==']'){
                s1.pop();
            }
            else if(s[i]=='{' && s1.top()=='}'){
                s1.pop();
            }
            else{
                s1.push(s[i]);
            }
        }
        if(!s1.empty()) return false;
        return true;
    }
};