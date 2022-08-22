class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& sh) {
        
        int n = s.size();
        int m = sh.size();
        vector<int> dup(n+1 , 0);
        for(auto &i : sh){
            if(i[2]==1){
                dup[i[0]]++;
                dup[i[1]+1]--;
            }
            else{
                dup[i[0]]--;
                dup[i[1]+1]++;
            }
        }
        for(int i=1;i<n+1;i++){
            dup[i]+=dup[i-1];
        }
//         for(int i=0;i<n;i++){
            
//             s[i]=s[i]+dup[i];
//             if(s[i]=='{'){
//                 s[i]='a';
//             }
//             else if(s[i]=='`'){
//                 s[i]='z';
//             }
//         }
        for(int i=0;i<n;i++){
            int inc = (s[i]-'a'+dup[i])%26;
            inc=(inc+26)%26;
            s[i]='a'+inc;
        }

        return s;
    }
};