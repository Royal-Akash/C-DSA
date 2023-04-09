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
    int total = 0;
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return 0;
        findpath(root, targetSum, 0);
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);
        return total;
    }
    
    void findpath(TreeNode* root, int targetSum , long long int sum){
        
        if(!root) return;
        
        sum+=root->val;
        if(sum==targetSum) total++;
        
        findpath(root->left, targetSum, sum);
        findpath(root->right, targetSum, sum);
        
    }
};

// TC = O(n^2)