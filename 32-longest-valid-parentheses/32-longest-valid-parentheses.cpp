// class Solution {
// public:
//     int longestValidParentheses(string s) {
        
//         int n = s.size();
//         int count=0;
//         stack<char>st;
//         stack<int> ind;
//         ind.push(-1);
        
//         for(int i=0;i<n;i++){
            
//             if(s[i]=='('){
//                 st.push(s[i]);
//                 ind.push(i);
//             }
//             else{
//                 if(!st.empty() && st.top()=='('){
//                     st.pop();
//                     ind.pop();
//                     count=max(count , i-ind.top());
//                 }
//                 else{
//                     ind.push(i);
//                 }
//             }
//         }
//         return count;
//     }
// };

class Solution {
public:
    int longestValidParentheses(string s) {
        
        int n = s.size();
        int count=0;
        // stack<char>st;
        stack<int> ind;
        ind.push(-1);
        
        for(int i=0;i<n;i++){
            
            if(s[i]=='('){
                // st.push(s[i]);
                ind.push(i);
            }
            else{
                ind.pop();
                if(!ind.empty()){
                    // st.pop();
                    
                    count=max(count , i-ind.top());
                }
                else{
                    ind.push(i);
                }
            }
        }
        return count;
    }
};