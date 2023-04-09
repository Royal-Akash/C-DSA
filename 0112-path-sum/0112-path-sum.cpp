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
    bool flag = false;
private:
    void findpath(TreeNode* root, int targetSum , int sum){
        if(!root) return;
        sum+=root->val;
        if(sum==targetSum && root->left==NULL && root->right==NULL){
            flag = true;
            return;
        }
        
        findpath(root->left , targetSum , sum);
        findpath(root->right, targetSum , sum);
        
    }
    
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        findpath(root , targetSum, 0);
        return flag; 
    }
};