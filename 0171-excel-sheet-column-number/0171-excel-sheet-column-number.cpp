class Solution {
public:
    int titleToNumber(string s) {
       int n = s.length();
       int ans = 0;
       for(int i=0;i<n;i++)
       {
           ans = ans * 26 + (s[i]-64); 
       }
       return ans;

    }
};