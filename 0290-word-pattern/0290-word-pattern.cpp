class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        unordered_map<string , char> word;
        unordered_map<char , string> alpha;
        
        int n =pattern.size() , i=0;
        stringstream str(s);
        string Nword;
        
        while(str >> Nword){
            if(i==n) return false;
            char c = pattern[i];
            if(alpha.count(c)!=word.count(Nword)) return false;
            
            if(alpha.count(c)){
                if((word[Nword]!=c) || (alpha[c]!=Nword)){
                    return false;
                }
            }
            else{
                    alpha.insert({c , Nword});
                    word.insert({Nword , c});
                }
                i++;
        }
        return i==n;
    }
};