class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        
        unordered_map<int, int>mp;
        int maxi = 0;
        int n = arr.size();
        for(int i=0;i<n;i++){
            
            int temp = arr[i] - difference;
            int ans = 0;
            if(mp.count(temp)){
                ans=mp[temp];
            }
            mp[arr[i]]=ans+1;
            maxi = max(maxi, mp[arr[i]]);
            
        }
        return maxi;
    }
};