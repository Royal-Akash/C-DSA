class Solution {
public:
    static bool comp(string &s1, string &s2){
        return s1.size()<s2.size();
    }
    bool compare(string & s1, string &s2){
        
        if(s2.size()+1==s1.size()){
                    int w1=0, w2=0;
                    while(w1<s2.size() && w2<s1.size()){
                        if(s2[w1]==s1[w2]){
                            w1++, w2++;
                        }
                        else{
                            w2++;
                        }
                    }
                    if(w1==s2.size()){
                        return true;
                    }
                    
                }
        return false;
        
    }
    int longestStrChain(vector<string>& nums) {
        int n = nums.size();
        vector<int>dp(n, 1);
        sort(nums.begin(), nums.end(), comp);
        
        int maxi = 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                
                if(compare(nums[i], nums[j]) && dp[i]<1+dp[j]){
                    dp[i]=1+dp[j];
                }
                
            }
            maxi = max(maxi , dp[i]);
        }
        return maxi;
    }
};