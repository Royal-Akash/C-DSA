class Solution {
public:
    string longestPalindrome(string s) {
        
        int n = s.size();
        int st=0, ed=n-1;
        int start=0, end=0;
        int count=0;
        for(int i=1;i<n;i++){
            st=i-1, ed=i+1;
            
            while(st>=0 && ed<n){
                if(s[st]!=s[ed]){
                    break;
                }
                else if(count<ed-st+1){
                    start=st;
                    end=ed;
                    count=ed-st+1;
                }
                st--;
                ed++;
            }
            st=i-1;
            ed=i;
            while(st>=0 && ed<n){
                if(s[st]!=s[ed]){
                    break;
                }
                else if(count<ed-st+1){
                    start=st;
                    end=ed;
                    count=ed-st+1;
                }
                st--;
                ed++;
            }
        }
        string ans;
        for(int i=start;i<=end;i++){
            ans+=s[i];
        }
        return ans;
    }
};