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
    bool checkTree(TreeNode* root) {
        if(root==NULL) return true;
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty()){
            TreeNode*node=st.top();
            st.pop();
            int ans = 0;
            if(node->left){
                st.push(node->left);
                ans+=st.top()->val;
            }
            if(node->right){
                st.push(node->right);
                ans+=node->right->val;
            }
            if(ans!=node->val && node->left && node->right) return false;
        }
        return true;
    }
};