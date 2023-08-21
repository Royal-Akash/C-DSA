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
    int findBal(TreeNode* root){
        if(root==NULL) return 0;
        
        int lf = findBal(root->left);
        if(lf==-1) return -1;
        int rt = findBal(root->right);
        if(rt==-1) return -1;
        
        if(abs(rt-lf)>1) return -1;
        return 1+max(lf, rt);
    }
    bool isBalanced(TreeNode* root) {
        return findBal(root)!=-1;
    }
};