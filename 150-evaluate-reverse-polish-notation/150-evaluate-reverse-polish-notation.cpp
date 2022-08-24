class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<int> s;
        int n = tokens.size();
        int sum=0;
        for(int i=0;i<n;i++){
            
            if(tokens[i]=="+"){
                int y = (s.top());
                s.pop();
                int z = (s.top());
                s.pop();
                int sum=z+y;
                s.push(sum);
            }
            else if(tokens[i]=="-"){
                int y = (s.top());
                s.pop();
                int z = (s.top());
                s.pop();
                int sum=z-y;
                s.push(sum);
            }
            else if(tokens[i]=="*"){
                int y = (s.top());
                s.pop();
                int z = (s.top());
                s.pop();
                int sum=z*y;
                s.push(sum);
            }
            else if(tokens[i]=="/"){
                int y = (s.top());
                s.pop();
                int z = (s.top());
                s.pop();
                int sum=z/y;
                s.push(sum);
            }
            else{
                int num=stoi(tokens[i]);
                s.push(num);
            }
            
        }
        int k = s.top();
        return k;
        
    }
};