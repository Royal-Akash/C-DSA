class Solution {
public:
    bool isAnagram(string s, string t) {
        
//         sort(s.begin() , s.end());
//         sort(t.begin() , t.end());
        
//         if(s.size()!=t.size()){
//             return false;
//         }
        
//         for(int i=0;i<s.size();i++){
            
//             if(s[i]!=t[i]){
//                 return false;
//             }
            
//         }
        
//         return true;
        
        if(s.size()!=t.size()){
            return false;
        }
        
        map<char , int> mp1 , mp2;
        
        for(auto c : s){
            mp1[c]++;
        }
        for(auto y : t){
            mp2[y]++;
        }
            
            for(int i=0;i<s.size();i++){
                
                if(mp1[s[i]]!=mp2[s[i]]){
                    return false;
                }
            }
        return true;
    }
};