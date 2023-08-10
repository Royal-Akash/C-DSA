class Solution {
public:
    string reverseWords(string s) {
        
        string temp = "";
        string ans = "";
        int left = 0 , right=s.length();
        while(left<right){
            if(s[left]!=' '){
                temp+=s[left];
            }
            else if(temp!=""){
                if(ans==""){
                    ans+=temp;
                }
                else{
                    ans=temp+" "+ans;
                }
                temp="";
            }
            left++;
        }
        if(temp!=""){
            if(ans==""){
                ans+=temp;
            }
            else{
                ans=temp+" "+ans;
            }
        }
        return ans;
    }
};