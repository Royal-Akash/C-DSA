class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int id, int vd) {
        
        int n = nums.size();
        
        if(n<id) return {-1, -1};
        int maxV=INT_MIN, minV=INT_MAX, maxid=-1, minid=-1;
        for(int i=0;i<n-id;i++){
            if(nums[i]>maxV){
                maxV=nums[i];
                maxid=i;
            }
            if(nums[i]<minV){
                minV=nums[i];
                minid=i;
            }
            if(abs(nums[i+id]-maxV)>=vd){
                return {maxid, i+id};
            }
            if(abs(nums[i+id]-minV)>=vd){
                return {minid, i+id};
            }
        }
        return {-1, -1};
    }
};