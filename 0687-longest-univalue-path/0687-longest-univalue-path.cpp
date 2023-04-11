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
    // int count1=0;
private:
 int countnodes(TreeNode* root, int& count){
        if(!root) return 0;
        
        int lefth = countnodes(root->left , count);
        int righth = countnodes(root->right , count);
        int lm = 0 , rm =0;
        if(root->left && root->left->val==root->val){
            lm = lefth+1;
        }
        if(root->right && root->right->val==root->val){
            rm = righth+1;
        }
        count = max(count, lm+rm);
        return max(lm , rm);
        
    }
    
public:
    int longestUnivaluePath(TreeNode* root) {
        
        int count = 0;
        countnodes(root, count);
        
        return count;
    }
};