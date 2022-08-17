class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> v = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        set<string> ans;
        for(auto word : words){
            string curr="";
            for(auto it : word){
                
                curr+=v[it-97];
                
            }
            ans.insert(curr);
        }
        return ans.size();
    }
};