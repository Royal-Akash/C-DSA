// class Solution {
    
// private:
//     void print(vector<int> nums , int index , vector<vector<int>>& ans){

//     if(index>=nums.size()){
//         ans.push_back(nums);
//         return;
//     }
        
//         for(int i=index;i<nums.size();i++){

//             swap(nums[index] , nums[i]);
//             print(nums , index+1 , ans);
//             swap(nums[index] , nums[i]);
//         }
        
//     }
    
// public:
//     vector<vector<int>> permute(vector<int>& nums) {
        
//         int index =0;
//         vector<vector<int>> ans;
//         print(nums , index , ans);
//         return ans;
        
//     }
// };


class Solution {
    
private:
    void print(vector<int> nums , int freq[] , vector<vector<int>>& ans , vector<int> &ds){

    if(ds.size()==nums.size()){
        ans.push_back(ds);
        return;
    }
        
        for(int i=0;i<nums.size();i++){
            if(!freq[i]){
                
                ds.push_back(nums[i]);
                freq[i]=1;
                print(nums , freq , ans , ds);
                freq[i]=0;
                ds.pop_back();
                
            }
        }
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        int index =0;
        vector<vector<int>> ans;
        vector<int> ds;
        int n = nums.size();
        // int freq[n]={0};
        int freq[n];
        for(int i=0;i<nums.size();i++) freq[i]=0;
        print(nums , freq , ans , ds);
        return ans;
        
    }
};