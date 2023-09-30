class Solution {
public:
    static bool comp(string &s1, string &s2){
        return s1.size()<s2.size();
    }
    int longestStrChain(vector<string>& nums) {
        int n = nums.size();
        vector<int>dp(n, 1), hash(n);
        sort(nums.begin(), nums.end(), comp);
        
        int maxi = 1,lastInd=0;
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if(nums[j].size()+1==nums[i].size()){
                    int w1=0, w2=0;
                    while(w1<nums[j].size() && w2<nums[i].size()){
                        if(nums[j][w1]==nums[i][w2]){
                            w1++, w2++;
                        }
                        else{
                            w2++;
                        }
                    }
                    if(w1==nums[j].size()){
                        dp[i]=max(dp[i], 1+dp[j]);
                        hash[i]=j;
                    }
                    
                }
            }
            if(maxi<dp[i]){
                maxi=dp[i];
                lastInd=i;
            }
        }
        
        vector<string>temp;
        temp.push_back(nums[lastInd]);
        while(hash[lastInd]!=lastInd){
            
            lastInd=hash[lastInd];
            temp.push_back(nums[lastInd]);
            
        }
        reverse(temp.begin(), temp.end());
        // return temp;
        for(auto it: temp){
            cout<<it<<" ";
        }cout<<endl;
        return maxi;
    }
};