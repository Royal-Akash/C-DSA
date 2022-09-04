class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        
        int n = s.size();
        int j=0;
        
        for(int i=0;i<n;i++){
            
            if(s[i]!='A'){
                char c = s[i];
                size_t f = s.find(c , i+1);
                
                if(distance[s[i]-'a']==(f-i-1)){
                    s[f]='A';
                    j++;
                }
                else{
                    return false;
                }
            }
        }
        
         return true;
    }
};