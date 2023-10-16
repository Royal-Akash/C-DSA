class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {

        int n = s.size();
        string ans = "";
        int count=0, i=0;
        string temp = "";
        while(i<n && count<k){
            if(s[i]=='0' && temp.size()==0){
                i++;
                continue;
            }
            temp+=s[i];
            if(s[i]=='1'){
                count++;
            }
            i++;
        }
        if(count==k){
            ans=temp;
        }
        // cout<<ans<<endl;
        for(int i=0;i<n;i++){
            int count=0;
            int j=i;
            string num = "";
            while(j<n && count<k){
                if(s[j]=='0' && num.size()==0){
                    j++;
                    continue;
                }
                num+=s[j];
                if(s[j]=='1'){
                    count++;
                }
                
                j++;
            }
            // cout<<num<<endl;
            if(count==k && ans.size()>num.size()){
                ans=num;
            }
            else if(count==k && ans.size()==num.size() && ans>num){
                ans=num;
            }
        }
        cout<<ans<<endl;
//         string result="";
//         int t = ans.size(), m=-1;
//         for(int i=0;i<t;i++){
//             if(ans[i]=='0'){
//                 m=i;
//             }
//             else{
//                 break;
//             }
//         }
//         if(m!=-1 && m<t){
//             result = ans.substr(m+1, t-m-1);
//         }
//         if(m==-1){
//             return ans;
//         }
        
//         // cout<<m<<endl;
        
        return ans;
        
    }
};