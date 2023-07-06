class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
    
    int n = nums.size();
    int i = 0;
    int j = 0;
    int sum = 0;
    int minLen = INT_MAX;
    
    while(j < n) {
        sum += nums[j];
        
        //window length less krne chah rahe hai
        while(sum >= target) {
            minLen = min(minLen, j-i+1);
            
            sum -= nums[i];
            //right sift of i
            i++;
        }
        j++;
    }
    
    return minLen == INT_MAX ? 0 : minLen;

    }
};