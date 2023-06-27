class Solution {
public:
    string removeKdigits(string num, int k) {
        
        int n = num.size();
        if(k>n || n==0) return "0";
        stack<char>st;
        st.push(num[0]);
        for(int i=1;i<n;i++){
            
            while(k>0 && !st.empty() && st.top()>num[i]){
                st.pop();
                k--;
            }
            st.push(num[i]);
            if(st.size()==1 && num[i]=='0') st.pop();
            
        }
        while(k!=0 && !st.empty()){
            st.pop();
            k--;
        }
        string res;
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        if(res.size()==0) return "0";
        return res;
    }
};