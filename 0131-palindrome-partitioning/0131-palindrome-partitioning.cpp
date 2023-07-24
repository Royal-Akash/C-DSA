class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>res;
        findP(0, s, ans, res);
        return ans;
    }
    
    void findP(int ind, string s, vector<vector<string>>&ans, vector<string>&res){
        
        if(ind==s.size()){
            ans.push_back(res);
            return;
        }
        for(int i=ind;i<s.size();i++){
            if(ispalindrome(s, ind, i)){
                res.push_back(s.substr(ind, i-ind+1));
                findP(i+1, s, ans, res);
                res.pop_back();
            }
        }
        
    }
    
    bool ispalindrome(string s, int start, int end){
        
        while(start<=end){
            if(s[start++]!=s[end--]){
                return false;
            }
        }
        return true;
    }
    
};