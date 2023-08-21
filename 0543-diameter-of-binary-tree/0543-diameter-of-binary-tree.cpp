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
public:
    int dia(TreeNode* root, int &ans){
        if(root == NULL) return 0;
        int lf = dia(root->left, ans);
        int rt = dia(root->right, ans);
        ans = max(ans, lf+rt);
        return 1+max(lf, rt);
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        dia(root, ans);
        return ans;
    }
};