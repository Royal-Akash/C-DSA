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
    TreeNode* build(vector<int>& postorder, int pstart, int pend, vector<int>& inorder, int istart, int iend, unordered_map<int, int>&mp){
        if(pstart>pend || istart>iend) return NULL;
        
        TreeNode* node = new TreeNode(postorder[pstart]);
        
        int proot = mp[postorder[pstart]];
        int remr = iend-proot;
        int reml = proot-istart;
        
        node->left = build(postorder, pstart+remr+1, pend, inorder, istart, proot-1, mp);
        node->right= build(postorder, pstart+1, pstart+remr, inorder, proot+1, iend, mp);
        
        return node;
        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int>mp;
        for(int i=0;i<=inorder.size()-1;i++){
            mp[inorder[i]]=i;
        }
        reverse(postorder.begin(), postorder.end());
        TreeNode* root = build(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1, mp);
        return root;
    }
};