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
    
    bool findsoln(TreeNode* root , long max , long min){
        
        if(root==NULL){
            return true;
        }
        
        if((root->val<max) && (root->val>min)){
            
            return findsoln(root->left , root->val , min) && findsoln(root->right , max , root->val);
            
        }
        else{
            return false;
        }  
    }
    
    bool isValidBST(TreeNode* root) {
        
        bool ans = findsoln(root , LONG_MAX , LONG_MIN);
        return ans;
        
    }
};