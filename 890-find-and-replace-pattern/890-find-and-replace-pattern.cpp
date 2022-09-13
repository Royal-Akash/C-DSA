// class Solution {
// public:
//     vector<int>countpattern(string word){
//         if(word.size()==0) return {};
//         vector<int>count;
//         unordered_map<char , int>mp;
//         int ind=0;
//         for(int i=0;i<word.size();i++){
//             if(mp.find(word[i])==mp.end()){
//                 mp.insert({word[i] , ind++});
//                 count.push_back(mp[word[i]]);
//             }
//             else{
//                 count.push_back(mp[word[i]]);
//             }
//         }
//         return count;
//     }
    
//     vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
//         int n = words.size();
//         vector<int>v = countpattern(pattern);
//         vector<string>ans;
//         for(int i=0;i<n;i++){
//             vector<int>v1 = countpattern(words[i]);
//             if(v1==v){
//                 ans.push_back(words[i]);
//             }
//         }
//             return ans;
//     }
// };




class Solution {
public:
   
    vector<char>countP(string word){
        
        unordered_map<char , char>mp;
        int j=0;
        vector<char>v1;
        for(int i=0;i<word.size();i++){
            
            if(mp.find(word[i])==mp.end())
            {
                mp.insert({word[i] , 'a'+j});
                j++;
                v1.push_back(mp[word[i]]);
            }
            else{
                v1.push_back(mp[word[i]]);
            }
            
        }
        return v1;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
       
        vector<char>v = countP(pattern);
        vector<string> ans;
        
        for(int i=0;i<words.size();i++){
            
            vector<char>word = countP(words[i]);
            
            if(word==v){
                ans.push_back(words[i]);
            }
            
        }
        return ans;
       
    }
};