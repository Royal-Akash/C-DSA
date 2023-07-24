class Solution {
public:
    string nxtPermutation(string s, int n){
        int ind=-1;
        for(int i=n-2;i>=0;i--){
            if(s[i]<s[i+1]){
                ind=i;
                break;
            }
        }
        if(ind!=-1){
            for(int i=n-1;i>=ind;i--){
                if(s[i]>s[ind]){
                    swap(s[i], s[ind]);
                    break;
                }
            }
            reverse(s.begin()+ind+1, s.end());
        }
        else{
            reverse(s.begin(), s.end());
        }
        return s;
        
    }
    string getPermutation(int n, int k) {
        string v;
        for(int i=1;i<=n;i++){
            v+=to_string(i);
        }
        for(int i=1;i<k;i++){
            v=nxtPermutation(v, n);
        }
        return v;
    }
};