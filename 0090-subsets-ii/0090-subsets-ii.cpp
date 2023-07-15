class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>>st;
        int n = nums.size();
        
        for(int i=0;i<(1<<n);i++){
            vector<int>ans;
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    ans.push_back(nums[j]);
                }
            }
            sort(ans.begin(), ans.end());
            st.insert(ans);
        }
        vector<vector<int>>ans;
        for(auto it : st){
            ans.push_back(it);
        }
        return ans;
    }
};