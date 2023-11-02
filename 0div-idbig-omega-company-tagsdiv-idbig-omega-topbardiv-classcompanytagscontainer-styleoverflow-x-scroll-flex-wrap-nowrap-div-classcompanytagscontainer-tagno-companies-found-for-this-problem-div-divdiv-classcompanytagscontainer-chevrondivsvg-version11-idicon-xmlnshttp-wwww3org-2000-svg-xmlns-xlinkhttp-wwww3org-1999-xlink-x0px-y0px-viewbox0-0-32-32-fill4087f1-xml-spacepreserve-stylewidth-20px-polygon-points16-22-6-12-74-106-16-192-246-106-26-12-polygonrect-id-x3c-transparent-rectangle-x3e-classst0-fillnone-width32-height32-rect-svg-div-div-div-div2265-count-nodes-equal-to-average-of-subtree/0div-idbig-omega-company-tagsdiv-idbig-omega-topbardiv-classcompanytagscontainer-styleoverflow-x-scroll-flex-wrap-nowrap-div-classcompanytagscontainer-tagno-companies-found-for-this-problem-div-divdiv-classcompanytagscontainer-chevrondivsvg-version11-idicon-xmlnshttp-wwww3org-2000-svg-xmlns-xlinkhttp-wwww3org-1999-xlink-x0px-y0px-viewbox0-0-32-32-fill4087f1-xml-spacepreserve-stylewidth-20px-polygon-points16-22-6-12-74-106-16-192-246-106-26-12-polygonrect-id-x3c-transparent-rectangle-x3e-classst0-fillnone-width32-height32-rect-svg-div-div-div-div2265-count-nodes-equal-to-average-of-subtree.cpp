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
    void count(TreeNode* root, int &num, int &sum){
        if(root==NULL) return;
        int data = root->val;
        sum+=data;
        num++;
        if(root->left) count(root->left, num, sum);
        if(root->right) count(root->right, num, sum);
    }
    void sol(TreeNode* root, int &ans){
        
        if(root==NULL) return;
        int num = 0, sum = 0;
        count(root, num, sum);
        int data = root->val;
        int avg = sum/num;
        if(avg==data) ans++;
        
        if(root->left) sol(root->left, ans);
        if(root->right) sol(root->right, ans);
        
    }
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        sol(root, ans);
        return ans;
    }
};