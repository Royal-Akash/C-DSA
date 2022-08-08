class Solution {
public:
    string simplifyPath(string p) {
        
        stack<string> st;
        string res;
        for(int i=0;i<p.size();i++){
            
            if(p[i]=='/'){
                continue;
            }
            
            string temp;
            while(i<p.size() && p[i]!='/'){
                
                temp+=p[i];
                i++;
            }
            if(temp=="."){
                continue;
            }
            else if(temp==".."){
                if(!st.empty()) st.pop();
            }
            else{
                st.push(temp);
            }
        } 
        
            while(!st.empty()){
                res='/'+st.top() + res;
                st.pop();
            }
            
            if(res.size()==0) return "/";
        
        return res;   
    }
};