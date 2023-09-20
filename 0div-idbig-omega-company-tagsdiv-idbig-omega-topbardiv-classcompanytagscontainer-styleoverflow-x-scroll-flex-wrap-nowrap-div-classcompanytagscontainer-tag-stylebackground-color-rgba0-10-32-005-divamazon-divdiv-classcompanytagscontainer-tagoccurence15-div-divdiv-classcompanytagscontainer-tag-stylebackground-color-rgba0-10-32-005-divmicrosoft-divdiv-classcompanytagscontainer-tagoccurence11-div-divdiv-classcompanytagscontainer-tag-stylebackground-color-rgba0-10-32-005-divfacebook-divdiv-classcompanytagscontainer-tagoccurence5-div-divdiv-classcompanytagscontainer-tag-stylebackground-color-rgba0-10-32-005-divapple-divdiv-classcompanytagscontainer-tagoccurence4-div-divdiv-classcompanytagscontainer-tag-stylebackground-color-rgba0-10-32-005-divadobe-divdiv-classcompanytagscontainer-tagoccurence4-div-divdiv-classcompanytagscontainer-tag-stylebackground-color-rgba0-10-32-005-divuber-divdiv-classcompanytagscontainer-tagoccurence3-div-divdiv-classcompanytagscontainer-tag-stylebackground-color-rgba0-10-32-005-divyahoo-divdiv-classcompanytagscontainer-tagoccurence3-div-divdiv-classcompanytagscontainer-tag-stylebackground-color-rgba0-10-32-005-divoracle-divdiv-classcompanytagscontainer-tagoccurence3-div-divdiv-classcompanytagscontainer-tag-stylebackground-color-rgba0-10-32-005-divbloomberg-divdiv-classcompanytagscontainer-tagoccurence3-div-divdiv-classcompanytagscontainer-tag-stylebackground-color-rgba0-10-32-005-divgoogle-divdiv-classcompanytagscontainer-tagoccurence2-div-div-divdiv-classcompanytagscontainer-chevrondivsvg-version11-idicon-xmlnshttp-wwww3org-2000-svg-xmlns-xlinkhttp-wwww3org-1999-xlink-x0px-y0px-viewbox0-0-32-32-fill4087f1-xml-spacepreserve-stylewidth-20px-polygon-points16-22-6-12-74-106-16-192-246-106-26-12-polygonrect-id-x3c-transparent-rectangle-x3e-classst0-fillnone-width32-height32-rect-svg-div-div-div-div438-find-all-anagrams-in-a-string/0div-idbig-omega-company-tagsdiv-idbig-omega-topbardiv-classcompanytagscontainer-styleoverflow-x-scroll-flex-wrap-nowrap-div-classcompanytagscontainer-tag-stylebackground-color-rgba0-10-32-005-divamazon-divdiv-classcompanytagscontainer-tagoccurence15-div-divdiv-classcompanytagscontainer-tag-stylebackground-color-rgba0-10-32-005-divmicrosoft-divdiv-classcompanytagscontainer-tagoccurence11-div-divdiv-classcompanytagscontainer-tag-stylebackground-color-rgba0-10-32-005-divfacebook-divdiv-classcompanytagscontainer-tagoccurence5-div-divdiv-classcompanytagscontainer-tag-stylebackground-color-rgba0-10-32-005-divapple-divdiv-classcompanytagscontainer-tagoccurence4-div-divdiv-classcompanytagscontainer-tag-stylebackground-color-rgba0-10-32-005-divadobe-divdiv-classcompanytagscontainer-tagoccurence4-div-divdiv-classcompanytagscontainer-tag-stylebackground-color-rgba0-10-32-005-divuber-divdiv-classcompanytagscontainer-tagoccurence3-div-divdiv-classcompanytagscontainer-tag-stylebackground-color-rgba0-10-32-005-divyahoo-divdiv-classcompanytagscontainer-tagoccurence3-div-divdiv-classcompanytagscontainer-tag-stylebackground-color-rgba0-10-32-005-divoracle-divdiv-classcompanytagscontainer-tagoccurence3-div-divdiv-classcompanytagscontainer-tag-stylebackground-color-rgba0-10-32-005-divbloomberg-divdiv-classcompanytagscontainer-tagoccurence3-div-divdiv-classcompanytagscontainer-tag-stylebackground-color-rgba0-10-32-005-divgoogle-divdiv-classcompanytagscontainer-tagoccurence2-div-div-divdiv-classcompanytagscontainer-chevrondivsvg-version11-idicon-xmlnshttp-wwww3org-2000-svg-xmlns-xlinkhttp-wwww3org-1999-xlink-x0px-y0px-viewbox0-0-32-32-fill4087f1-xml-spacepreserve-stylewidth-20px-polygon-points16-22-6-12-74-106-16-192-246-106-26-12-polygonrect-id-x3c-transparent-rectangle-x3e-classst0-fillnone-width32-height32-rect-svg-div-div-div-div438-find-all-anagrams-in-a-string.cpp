class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = p.size();
        int m = s.size();
        vector<int>sol;
        if(n>m) return sol;
        vector<int>v(26, 0);
        for(int i=0;i<n;i++){
            v[p[i]-'a']++;
        }
        vector<int>ans(26, 0);
        
        for(int i=0;i<n;i++){
            ans[s[i]-'a']++;
        }
        if(ans==v) sol.push_back(0);
        if(n==m && ans==v) return sol;
        ans[s[0]-'a']--;
        int j=n, i=1;
        while(j<m){
            ans[s[j]-'a']++;
            if(ans==v){
                sol.push_back(i);
            }
            ans[s[i]-'a']--;
            i++;
            j++;
            
        }
        return sol;
        
    }
};