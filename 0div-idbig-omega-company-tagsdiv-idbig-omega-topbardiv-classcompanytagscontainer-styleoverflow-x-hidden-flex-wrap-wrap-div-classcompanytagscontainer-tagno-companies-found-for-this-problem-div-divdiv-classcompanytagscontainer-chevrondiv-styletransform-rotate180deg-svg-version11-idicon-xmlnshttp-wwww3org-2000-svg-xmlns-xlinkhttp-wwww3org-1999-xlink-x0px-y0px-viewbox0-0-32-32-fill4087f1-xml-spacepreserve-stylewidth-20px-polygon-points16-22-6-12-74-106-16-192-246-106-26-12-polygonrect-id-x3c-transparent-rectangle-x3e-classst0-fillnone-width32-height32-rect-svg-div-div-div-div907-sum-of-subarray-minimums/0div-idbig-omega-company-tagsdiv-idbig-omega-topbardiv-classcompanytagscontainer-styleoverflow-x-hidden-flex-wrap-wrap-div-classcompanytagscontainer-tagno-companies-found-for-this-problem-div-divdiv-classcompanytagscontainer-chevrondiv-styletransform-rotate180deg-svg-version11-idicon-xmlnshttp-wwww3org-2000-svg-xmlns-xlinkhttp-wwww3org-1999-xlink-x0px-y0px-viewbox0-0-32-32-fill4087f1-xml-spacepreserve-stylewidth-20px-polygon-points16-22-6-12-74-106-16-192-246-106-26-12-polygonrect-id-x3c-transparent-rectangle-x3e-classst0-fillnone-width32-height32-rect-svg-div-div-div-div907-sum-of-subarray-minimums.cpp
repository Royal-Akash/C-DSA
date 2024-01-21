class Solution {
public:
    vector<int>findnsl(vector<int>&arr){
        
        int n = arr.size();
        vector<int>nsl(n);
        stack<int>st;
        
        int i=0;
        while(i<n){
            
            if(st.empty()){
                nsl[i]=-1;
            }
            else{
                while(!st.empty() && arr[st.top()]>=arr[i]){
                    st.pop();
                }
                nsl[i]= st.empty() ? -1 : st.top();
            }
            st.push(i);
            i++;
        }
        
        return nsl;
        
    }
    
    vector<int>findnsr(vector<int>&arr){
        
        int n = arr.size();
        vector<int>nsr(n);
        stack<int>st;
        
        int i=n-1;
        while(i>=0){
            
            if(st.empty()){
                nsr[i]=n;
            }
            else{
                while(!st.empty() && arr[st.top()]>arr[i]){
                    st.pop();
                }
                nsr[i]= st.empty() ? n : st.top();
            }
            st.push(i);
            i--;
        }
        
        return nsr;
        
    }
    int sumSubarrayMins(vector<int>& arr) {
        
        vector<int>nsl = findnsl(arr);
        vector<int>nsr = findnsr(arr);
        int n = arr.size();
        long long sum = 0;
        long long mod = 1e9+7;
        for(int i=0;i<n;i++){
            
            long long left = i-nsl[i];
            long long right = nsr[i]-i;
            long long total = (left*right);
            sum = (sum + total*arr[i])%mod;
            
        }
        return sum;
    }
};