class Solution {
public:
    
    void printf(vector<int>& nums , int n , vector<vector<int>>&ans , int ind , vector<int>& output){
        
        if(ind>=n){
            ans.push_back(output);
            return ;
            
        }
        printf(nums , n , ans , ind+1 , output);
        output.push_back(nums[ind]);
        printf(nums , n , ans , ind+1 , output);
        output.pop_back();
        
    }
    
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> output;
        printf(nums , n , ans , 0 , output);
        return ans;
    }
};