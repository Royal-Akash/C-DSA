class Solution {
public:
    int compareVersion(string v1, string v2) {
        int n = v1.size(), m = v2.size();
        int i=0, j=0;
        
        while(i<n || j<m){
            long long s1=0, s2 = 0;
            while(i<n && v1[i]!='.'){
                s1= s1*10 + (v1[i]-'0');
                i++;
            }
            while(j<m && v2[j]!='.'){
                s2= s2*10 + (v2[j]-'0');
                j++;
            }
            if(s1<s2) return -1;
            else if(s1>s2) return 1;
            i++;
            j++;
        }cout<<endl;
        return 0;
    }
};