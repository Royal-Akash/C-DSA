class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        
        unordered_map<int, int>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        
        set<int>st;
        for(auto it:mp){
            int n = st.size();
            st.insert(it.second);
            if(n==st.size()) return false;
        }
        return true;
    }
};