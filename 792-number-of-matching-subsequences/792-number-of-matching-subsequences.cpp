class Solution {
public:

int numMatchingSubseq(string s, vector<string>& words) {
    int count=0;
    vector<vector<int>>charindex(26);
    for(int i=0;i<s.size();i++){
        charindex[s[i]-'a'].push_back(i);
    }
    for(int i=0;i<words.size();i++){
        bool issub=true;
         int current=-1;
    for(char w: words[i]){
        
        auto it=upper_bound(charindex[w-'a'].begin(),charindex[w-'a'].end(),current);
        if(it==charindex[w-'a'].end()){
            issub=false;
            break;
        }
        else{
            current = *it;
        }
                            
      }
        if(issub){
         count++;
        }
    }
  return count;
}
};
