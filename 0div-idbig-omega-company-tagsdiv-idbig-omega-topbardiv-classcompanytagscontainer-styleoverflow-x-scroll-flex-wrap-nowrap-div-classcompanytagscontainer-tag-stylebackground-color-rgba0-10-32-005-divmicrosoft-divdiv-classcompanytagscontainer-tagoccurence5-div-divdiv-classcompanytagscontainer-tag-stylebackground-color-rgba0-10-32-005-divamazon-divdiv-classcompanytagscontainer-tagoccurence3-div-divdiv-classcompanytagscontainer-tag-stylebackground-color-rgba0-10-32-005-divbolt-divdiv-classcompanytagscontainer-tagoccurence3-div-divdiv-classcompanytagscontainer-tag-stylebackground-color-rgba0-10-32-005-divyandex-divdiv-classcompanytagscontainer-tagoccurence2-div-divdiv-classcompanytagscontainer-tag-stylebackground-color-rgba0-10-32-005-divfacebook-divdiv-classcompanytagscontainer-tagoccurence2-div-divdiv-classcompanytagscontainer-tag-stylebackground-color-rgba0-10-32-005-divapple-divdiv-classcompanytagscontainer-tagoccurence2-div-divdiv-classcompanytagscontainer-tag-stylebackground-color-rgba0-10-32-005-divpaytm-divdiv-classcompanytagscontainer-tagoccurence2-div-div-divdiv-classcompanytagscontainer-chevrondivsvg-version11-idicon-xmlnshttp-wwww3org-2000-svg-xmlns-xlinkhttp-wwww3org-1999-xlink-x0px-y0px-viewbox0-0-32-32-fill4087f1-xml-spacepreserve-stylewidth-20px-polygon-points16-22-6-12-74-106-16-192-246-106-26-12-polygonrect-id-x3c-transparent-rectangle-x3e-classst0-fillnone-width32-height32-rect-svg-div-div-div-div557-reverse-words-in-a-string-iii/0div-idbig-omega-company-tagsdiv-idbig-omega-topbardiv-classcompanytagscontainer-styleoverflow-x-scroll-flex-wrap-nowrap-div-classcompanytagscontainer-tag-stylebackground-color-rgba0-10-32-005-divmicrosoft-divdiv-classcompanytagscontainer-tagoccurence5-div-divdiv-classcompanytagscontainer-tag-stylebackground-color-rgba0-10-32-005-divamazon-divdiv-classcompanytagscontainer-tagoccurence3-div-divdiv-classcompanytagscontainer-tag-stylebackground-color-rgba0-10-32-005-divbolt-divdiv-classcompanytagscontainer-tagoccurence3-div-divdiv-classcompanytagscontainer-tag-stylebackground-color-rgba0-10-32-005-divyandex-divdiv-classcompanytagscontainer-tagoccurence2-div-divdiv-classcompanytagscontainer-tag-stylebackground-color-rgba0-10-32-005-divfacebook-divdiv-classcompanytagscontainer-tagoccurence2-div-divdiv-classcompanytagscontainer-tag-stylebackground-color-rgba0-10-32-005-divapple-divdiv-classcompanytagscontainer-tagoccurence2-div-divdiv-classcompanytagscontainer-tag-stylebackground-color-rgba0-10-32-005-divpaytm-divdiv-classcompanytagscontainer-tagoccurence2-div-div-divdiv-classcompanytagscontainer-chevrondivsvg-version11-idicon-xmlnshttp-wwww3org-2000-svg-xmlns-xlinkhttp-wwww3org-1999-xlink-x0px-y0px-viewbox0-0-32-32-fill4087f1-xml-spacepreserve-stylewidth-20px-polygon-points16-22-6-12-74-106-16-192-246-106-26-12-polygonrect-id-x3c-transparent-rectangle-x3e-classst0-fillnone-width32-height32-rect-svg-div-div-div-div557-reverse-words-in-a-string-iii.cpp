class Solution {
public:
    string reverseWords(string s) {
        string word;
        stringstream str(s);
        string ans;
        // while(str>>word){
        //     reverse(word.begin(), word.end());
        //     if(ans.empty()){
        //         ans+=word;
        //     }
        //     else{
        //         ans+=" "+word;
        //     }
        // }
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i]==' ' && word.empty()){
                word+=ans;
                ans="";
                continue;
            }
            else if(s[i]==' ' && !word.empty()){
                word+=" "+ans;
                ans="";
                continue;
            }
            else if(s[i]!=' '){
                ans = s[i]+ans;
            }
        }
        if(!ans.empty() && !word.empty()){
            word+=" "+ans;
        }
        else{
            word+=ans;
        }
        return word;
    }
};