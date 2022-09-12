#define ll long long
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        ll xy=0;
        for(ll it : nums) xy^=it;
        
        xy&=-xy; // This method getting the last set bit;
        vector<int>ans = {0,0};
        for(ll it : nums){
            if(xy&it) ans[0]^=it;
            else{
                ans[1]^=it;
            }
        }
        return ans;
    }
};