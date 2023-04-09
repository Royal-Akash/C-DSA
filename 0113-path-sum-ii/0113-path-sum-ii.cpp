/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
     vector<vector<int>>ans;
private:
     void getPath(TreeNode* root, int targetSum , int sum , vector<int>&arr){
        
        if(!root) return;
        
        arr.push_back(root->val);
        sum+=root->val;
        
        if(sum==targetSum && root->left==NULL && root->right==NULL){
            ans.push_back(arr);
        }
        getPath(root->left, targetSum, sum, arr);
        getPath(root->right, targetSum, sum, arr);
        
        arr.pop_back();
        
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<int>arr;
        getPath(root, targetSum , 0, arr);
        return ans;
        
    }
};