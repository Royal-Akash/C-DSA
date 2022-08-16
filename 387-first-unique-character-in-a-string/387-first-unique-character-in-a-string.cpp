class Solution {
public:
    int firstUniqChar(string s) {
        
        // vector<int> fre(26);
        unordered_map<char , int> fre;
        for(int i=0;i<s.size();i++){
            // fre[s[i]-'a']++;
            fre[s[i]]++;
        }
        
        for(int i=0;i<s.size();i++){
            // if(fre[s[i]-'a']==1){
            //     return i;
            // } 
            if(fre[s[i]]==1){
                return i;
            } 
        }
        return -1;
    }
};