class Solution {
public:
    string longestPalindrome(string s) {
        
        int n = s.size();
        int start = 0, end = 0;
        int count = 0;
        for(int i=1;i<n;i++){
            
            int left = i-1, right = i+1;
            while(left>=0 && right<n){
                if(s[left]!=s[right]){
                    break;
                }
                else if(right-left+1>count){
                    count=right-left+1;
                    start=left, end=right;
                }
                left--, right++; 
            }
            left=i-1, right=i;
            while(left>=0 && right<n){
                if(s[left]!=s[right]){
                    break;
                }
                else if(right-left+1>count){
                    count=right-left+1;
                    start=left, end=right;
                }
                left--, right++; 
            }
        }
        string ans;
        for(int i=start;i<=end;i++){
            ans+=s[i];
        }
        return ans;
    }
};