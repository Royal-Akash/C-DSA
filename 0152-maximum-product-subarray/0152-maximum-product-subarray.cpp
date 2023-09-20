class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n = nums.size();
        int maxi1 = INT_MIN;
        int maxi2 = INT_MIN;
        int ans1 = 1, ans2 = 1;;
        for(int i=0;i<n;i++){
            ans1 = ans1*nums[i];
            ans2 = ans2*nums[n-i-1];
            maxi1 = max(maxi1, ans1);
            maxi2 = max(maxi2, ans2);
            if(ans1 == 0) ans1 = 1;
            if(ans2 == 0) ans2 = 1;
        }
        return max(maxi1, maxi2);
    }
};