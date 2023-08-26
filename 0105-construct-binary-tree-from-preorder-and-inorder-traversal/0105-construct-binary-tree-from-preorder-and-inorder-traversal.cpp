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
    TreeNode* build(vector<int>& preorder, int pstart, int pend, vector<int>& inorder, int istart, int iend, unordered_map<int, int>&mp){
        if(pstart>pend || istart>iend) return NULL;
        
        TreeNode* node = new TreeNode(preorder[pstart]);
        
        int proot = mp[preorder[pstart]];
        int reml = proot - istart;
        
        node->left = build(preorder, pstart+1, pstart+reml, inorder, istart, proot-1, mp);
        node->right = build(preorder, pstart+reml+1, pend, inorder, proot+1, iend, mp);
        
        return node;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        unordered_map<int, int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        TreeNode* root = build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, mp);
        return root;
        
    }
};