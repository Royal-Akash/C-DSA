class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
//         map<char , int> mp;
        
//         for(int i=0;i<s.size();i++){
            
//             mp[s[i]]=0;
            
//         }
//         int count=0 , prev=0;
//         for(int i=0;i<s.size();i++){
            
//             if(mp[s[i]]==0 || mp[s[i]]==1){
//                 mp[s[i]]++;
                
//                 if(mp[s[i]]==2){
                    
//                     for(auto &p: mp){
//                         p.second=0;
//                     }
//                     mp[s[i]]=1;
                    
//                     count=0;
//                 }
//                 count++;
//                 // prev=count;
//                 prev=max(prev , count);
//             }
            
//         }
//         return prev;
        
        vector<int> mp(256 , -1);
        int n = s.size();
        int left=0 , right =0;
        int len = 0;
        
        while(right<n){
            
            if(mp[s[right]]!=-1) left = max(mp[s[right]]+1 , left);
            
            mp[s[right]]=right;
            
            
            
            len = max(len , right-left+1);
            right++;
            
        }
        return len;
        
    }
};