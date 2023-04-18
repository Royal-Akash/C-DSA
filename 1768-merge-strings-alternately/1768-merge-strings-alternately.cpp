// class Solution {
// public:
//     string mergeAlternately(string word1, string word2) {
        
//         int n = word1.size();
//         int m = word2.size();
//         string ans;
//         for(int i=0;i<max(n, m);i++){
//             if((i<(n)) && (i<(m))){
//                 ans+=(word1[i]+word2[i]);
//             }
//             else if(i>=n){
//                 ans+=word2[i];
//             }
//             else if(i>=m){
//                 ans+=word1[i];
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        
        int n = word1.size();
        int m = word2.size();
        string ans;
        for(int i=0;i<max(n, m);i++){
            if((i<n) && (i<m)){
                ans+=(word1[i]);
                ans+=word2[i];
            }
            else if(i>=n){
                ans+=word2[i];
            }
            else if(i>=m){
                ans+=word1[i];
            }
        }
        return ans;
    }
};
