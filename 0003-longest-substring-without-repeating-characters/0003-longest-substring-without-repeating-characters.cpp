class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        map<char, int>mp;
        int cnt = 0;
        int n = s.size();
        int maxcnt = 0;
        int left = 0, right = 0;
        
        while(right<n){
            
            // if(mp.find(s[right])==mp.end()){
            //     right++;
            //     cnt++;
            //     mp[s[right]]=right;
            // }
            if(mp.find(s[right])!=mp.end()){
                left = max(mp[s[right]]+1,left);
            }
                maxcnt = max(maxcnt, right-left+1);
                
                mp[s[right]]=right;
                right++;
            
        }
        // maxcnt = max(maxcnt, cnt);
        return maxcnt;
        
    }
};