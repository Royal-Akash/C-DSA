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
private:
    void findInorder(TreeNode* root ,vector<int>&inorder){
        
        if(root==NULL) return;
        
        findInorder(root->left , inorder);
        inorder.push_back(root->val);
        findInorder(root->right , inorder);
        
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int>inorder;
        findInorder(root , inorder);
        return inorder;
        
        
    }
};