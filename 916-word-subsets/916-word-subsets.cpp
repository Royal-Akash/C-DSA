class Solution {
public:
    vector<int> get_fre(string s){
        
        vector<int> temp(26 , 0);
        for(int i=0;i<s.size();i++){
            
            temp[s[i]-'a']++;
            
        }
        return temp;
        
    }
    
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        
        
        vector<int>max_fre(26 , 0);
        for(int i=0;i<B.size();i++){
            
           vector<int> temp=get_fre(B[i]); 
            
            for(int j=0;j<26;j++){
                max_fre[j]=max(temp[j] , max_fre[j]);
            }
            
        }
        vector<string> ans;
        for(int i=0;i<A.size();i++){
            
            vector<int> get = get_fre(A[i]);
            for(int j=0;j<26;j++){
                if(max_fre[j]>get[j]){
                    goto h;
                    
                }
                
            }
            ans.push_back(A[i]);
            h:;
                
             
        }
       return ans;
    }
};