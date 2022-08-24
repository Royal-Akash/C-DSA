////////////////////////////////// Its give TLE /////////////////////////////////////

// class Solution {
//     void findsum(vector<int>& arr, int target, set<vector<int>> &ans ,vector<int> &st , int ind){
        
//         if(ind==arr.size()){
//             if(target==0){
//                 ans.insert(st);
//             }
//             return;
//         }
//         if(arr[ind]<=target){
//             st.push_back(arr[ind]);
//             findsum(arr , target-arr[ind] , ans , st , ind+1);
//             st.pop_back();
//         }
//         findsum(arr , target , ans , st , ind+1);
//     }
    
// public:
//     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//         sort(candidates.begin() , candidates.end());
//         set<vector<int>> ans;
//         vector<int> st;
//         findsum(candidates , target , ans , st ,0);
//         vector<vector<int>> sum;
//         for(auto &it:ans){
//             sum.push_back(it);
//         }
//         return sum;
        
//     }
// };


class Solution {
    void findsum(vector<int>& arr, int target, vector<vector<int>> &ans ,vector<int> &st , int ind){
        
        // if(ind==arr.size()){
            if(target==0){
                ans.push_back(st);
                return;
            }
            
        
        for(int i=ind;i<arr.size();i++){
           if(i>ind && arr[i]==arr[i-1]) continue;
            
            if(arr[i]>target) break;
            
            st.push_back(arr[i]);
            findsum(arr , target-arr[i] , ans , st , i+1);
            st.pop_back();
         
        }
}
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin() , candidates.end());
        vector<vector<int>> ans;
        vector<int> st;
        findsum(candidates , target , ans , st ,0);
        
        return ans;
        
    }
};
