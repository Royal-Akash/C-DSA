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
    void getleaf(TreeNode* root, vector<string>&ans, vector<int>&s){
        
        if(root==NULL) return;
        s.push_back(root->val);
        
        if(root->left==NULL && root->right==NULL){
            string num = "";
            num+=to_string(s[0]);
            for(int i=1;i<s.size();i++){
                num=num+"->"+to_string(s[i]);
            }
            ans.push_back(num);
        }
        if(root->left){
            getleaf(root->left, ans, s);
        }
        if(root->right){
            getleaf(root->right, ans, s);
        }
        
        s.pop_back();
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        
        vector<string>ans;
        vector<int>s;
        getleaf(root, ans, s);
        return ans;
        
    }
};