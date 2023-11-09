class Solution {
public:
    int countHomogenous(string s) {
        
//         int ans = 0;
//         s+='$';
//         int n = s.size();
//         unordered_map<string, int>mp;
//         string temp = "";
//         string ans1 = "";
//         for(int i=0;i<n;i++){
            
//             if(s[i]==s[i+1]){
//                 temp+=s[i];
//                 mp[temp]++;
//                 if(temp.size()>1){
//                     ans1=s[i];
//                     mp[ans1]++;
//                 }
//             }
//             else{
//                 temp+=s[i];
//                 mp[temp]++;
//                 if(temp.size()>1){
//                     ans1=s[i];
//                     mp[ans1]++;
//                 }
//                 temp="";
//             }
            
//         }
//         for(auto it:mp){
//             cout<<it.first<<" "<<it.second<<endl;
//             ans+=it.second;
//         }
//         return ans;
        int M=1e9+7;
        map<char,int>mp;
        int ans=0;
        mp[s[0]]++;
        ans+=1;
        for(int i=1;i<s.length();i++){
            if(s[i]!=s[i-1]){
                mp.erase(s[i-1]);
                mp[s[i]]++;
                ans+=1;
            }
            else{
                mp[s[i]]++;
                ans+=mp[s[i]];
                ans=ans%M;
            }
        }
        return ans;
    }
};