class Solution {
public:
    vector<int>countpattern(string word){
        if(word.size()==0) return {};
        vector<int>count;
        unordered_map<char , int>mp;
        int ind=0;
        for(int i=0;i<word.size();i++){
            if(mp.find(word[i])==mp.end()){
                mp.insert({word[i] , ind++});
                count.push_back(mp[word[i]]);
            }
            else{
                count.push_back(mp[word[i]]);
            }
        }
        return count;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        int n = words.size();
        vector<int>v = countpattern(pattern);
        vector<string>ans;
        for(int i=0;i<n;i++){
            vector<int>v1 = countpattern(words[i]);
            if(v1==v){
                ans.push_back(words[i]);
            }
        }
            return ans;
    }
};