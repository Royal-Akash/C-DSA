class Solution {
public:
    string reverseWords(string s) {
        string word;
        stringstream str(s);
        string ans;
        while(str>>word){
            
            reverse(word.begin(), word.end());
            if(ans.empty()){
                ans+=word;
            }
            else{
                ans+=" "+word;
            }
            
        }
        
        return ans;
    }
};