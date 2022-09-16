class Solution {
public:
    int calculate(string s) {
        
        int n=s.size();
        stack<int>st;
        if(n==0) return 0;
        char sign = '+';
        int num=0;
        for(unsigned int i=0;i<n;i++){

            if(isdigit(s[i])){
                num = num*10+(s[i]-'0');
            }
            if(!isdigit(s[i]) && !isspace(s[i]) || i==n-1){
                if(sign =='+'){
                    st.push(num);
                }
                else if(sign =='-'){
                    st.push(-num);
                }
                else{
                    int ki;
                    if(sign=='*'){
                        ki = st.top()*num;
                    }
                    else{
                        ki = st.top()/num;
                    }
                    st.pop();
                    st.push(ki);
                }
                sign = s[i];
                num=0;
            }
        }
        int ans=0;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    
//     int calculate(string s) {
//     stack<int> myStack;
//     char sign = '+';
//     int res = 0, tmp = 0;
//     for (unsigned int i = 0; i < s.size(); i++) {
//         if (isdigit(s[i]))
//             tmp = 10*tmp + s[i]-'0';
//         if (!isdigit(s[i]) && !isspace(s[i]) || i == s.size()-1) {
//             if (sign == '-')
//                 myStack.push(-tmp);
//             else if (sign == '+')
//                 myStack.push(tmp);
//             else {
//                 int num;
//                 if (sign == '*' )
//                     num = myStack.top()*tmp;
//                 else
//                     num = myStack.top()/tmp;
//                 myStack.pop();
//                 myStack.push(num);
//             } 
//             sign = s[i];
//             tmp = 0;
//         }
//     }
//     while (!myStack.empty()) {
//         res += myStack.top();
//         myStack.pop();
//     }
//     return res;

    }
};