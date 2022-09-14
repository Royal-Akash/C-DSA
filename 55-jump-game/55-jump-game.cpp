class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size()-1;
        
        // for(int i=n;i>=0;i--){
        //     if(i+nums[i]>=n){
        //         n=i;
        //     }
        // }
        // return n==0;
        int reach=0;
        for(int i=0;i<=n;i++){
            if(reach<i){
                return false;
            }
            reach=max(reach , i+nums[i]);
        }
        return true;
    }
};