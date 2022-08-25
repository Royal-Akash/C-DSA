class Solution {
public:
    bool canConstruct(string r, string m){
        
        unordered_map<char , int> mp(26);
        for(int i=0;i<m.size();i++){
            mp[m[i]]++;
        }
        for(int i=0;i<r.size();i++){
            if(mp[r[i]]==0) return false;
            else{
                mp[r[i]]--;
            }
        }
        return true;
        
//         vector<int> mp(26 , 0);
//         for(int i=0;i<m.size();i++){
//             mp[m[i]-'a']++;
//         }
        
//         for(int i=0;i<r.size();i++){
//             if(mp[r[i]-'a']==0) return false;
//             else{
//                 mp[r[i]-'a']--;
//             }
//         }
//         return true;
    }
};