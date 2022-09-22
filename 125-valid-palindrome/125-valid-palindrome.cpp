class Solution {
public:
    bool isPalindrome(string s) {
        
        string temp;
        int n = s.size()-1;
        
        for(int i=0;i<=n;i++){
            char ch = s[i];
            if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9'))
            {
                temp+=s[i];
            }
        }
        // cout<<temp<<endl;
        for(int i=0;i<temp.size();i++){
            if(temp[i]>='A' && temp[i]<='Z')
            {
            temp[i]=temp[i]-'A'+'a';   
            }
         }
        string y = temp;
        reverse(y.begin() , y.end());
        // cout<<y<<" "<<temp<<endl;
        if(y==temp){
            return true;
        }
        else{
            return false;
        }
    }
};