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
    void getleaf(TreeNode* root, vector<string>&ans, string s){
        
        if(root==NULL) return;
        if(root->left || root->right){
            s+=to_string(root->val)+"->";
        }
        else{
            s+=to_string(root->val);
            ans.push_back(s);
        }
        if(root->left){
            getleaf(root->left, ans, s);
        }
        if(root->right){
            getleaf(root->right, ans, s);
        }
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        
        vector<string>ans;
        string s="";
        getleaf(root, ans, s);
        return ans;
        
    }
};