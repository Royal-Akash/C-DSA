class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i =0;
        int j =0;
        int ans =INT_MIN;
        int countzero = 0;

        while(j < nums.size()){
            if(nums[j] == 0) {
                countzero++;
            }
            while(countzero > 1) {
                if(nums[i] ==0){
                    countzero--;
                }
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans-1;
    }
};