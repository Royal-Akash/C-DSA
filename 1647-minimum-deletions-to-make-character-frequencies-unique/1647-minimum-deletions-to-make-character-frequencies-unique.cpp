class Solution {
public:
    int minDeletions(string s) {
        
        int n = s.size();
        if(n==1) return 0;
        unordered_map<char, int>mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        set<int>st;
        int count =0;
        for(auto it:mp){
            if(!st.count(it.second)){
                st.insert(it.second);
            }
            else{
                int num = it.second;
                while(st.count(num)){
                    count++;
                    num--;
                }
                if(num!=0){
                    st.insert(num);
                }
            }
        }
        return count;
        
    }
};