class Solution {
public:
    int find(vector<int>&num){
        int n = num.size();
        vector<int>Lsmaller(n);
        stack<int>st1;
        for(int i=0;i<n;i++){
            int curr = num[i];
            while(!st1.empty() && num[st1.top()]>=curr){
                st1.pop();
            }
            if(!st1.empty()){
                Lsmaller[i]=st1.top()+1;
            }
            else{
                Lsmaller[i]=0;
            }
            st1.push(i);
        }
        
        vector<int>Rsmaller(n, 0);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            int curr = num[i];
            while(!st.empty() && num[st.top()]>=curr){
                st.pop();
            }
            if(!st.empty()){
                Rsmaller[i]=st.top()-1;
            }
            else{
                Rsmaller[i]=n-1;
            }
            st.push(i);
        }
        
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            ans = max(ans, num[i]*(Rsmaller[i]-Lsmaller[i]+1));
        }
        return ans;
        
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        int result = 0;
        vector<int>ans(m, 0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                    ans[j]+=1;
                }
                else{
                    ans[j]=0;
                }
            }
            result = max(result, find(ans));
        }
        return result;
    }
};