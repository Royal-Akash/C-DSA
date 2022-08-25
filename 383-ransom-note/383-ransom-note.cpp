class Solution {
public:
    bool canConstruct(string r, string m){
        
        // sort(r.begin() , r.end());
        // sort(m.begin(), m.end());
        // for(int i=0;i<m.size();i++){
        //     // if(i<r.size()){
        //     // if(m[i]!=r[i]) return false;}
        //     if(m.find(r[i] , i )==m.end()) return false;
        // }
        // return true;
        
        // vector<int> v(26, 0);
        // for(int i=0;i<m.size;i++){
        //     v[i]=m[i]-'a';
        // }
        
        unordered_map<char , int> mp;
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
    }
};