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
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL) return false;
        unordered_map<int, int>mp;
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty()){
            
            TreeNode*node = st.top();
            st.pop();
            int sol = k-node->val;
            if(mp.count(sol)){
                return true;
                break;
            }
            if(node->left){
                st.push(node->left);
            }
            if(node->right){
                st.push(node->right);
            }
            mp[node->val]++;
            
        }
        return false;
    }
};