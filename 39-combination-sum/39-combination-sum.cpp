class Solution {

    void findsum(vector<int>& stu, int target , vector<int> &st, vector<vector<int>>&ans , int ind){
        if(ind==stu.size()){
            if(target==0){
                ans.push_back(st);
            }
            return;
        }
        
        if(stu[ind]<=target){
            st.push_back(stu[ind]);
            findsum(stu , target-stu[ind] , st , ans , ind);
            st.pop_back();
        }
        findsum(stu , target , st , ans , ind+1);
    }
    
  public:  
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int> st;
        findsum(candidates , target , st , ans , 0);
        return ans;
    }
};