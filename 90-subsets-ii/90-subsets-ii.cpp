class Solution {
    
    void findsum(vector<int>& nums ,vector<vector<int>> &ans ,vector<int> &st, int ind){
        
        ans.push_back(st);
        for(int i=ind;i<nums.size();i++){
            
            if(i!=ind && nums[i]==nums[i-1]) continue;
            st.push_back(nums[i]);
            findsum(nums , ans , st , i+1);
            st.pop_back();
        }
        
    }
    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        vector<vector<int>> ans;
        vector<int> st;
        findsum(nums , ans , st , 0);
        return ans;
    }
};