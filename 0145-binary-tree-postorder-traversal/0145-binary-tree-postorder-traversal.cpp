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

// Using single stack
//         vector<int>ans;
//         if(root==NULL) return ans;
//         stack<TreeNode*>st;
//         st.push(root);
        
//         while(!st.empty()){
            
//             root=st.top();
//             st.pop();
//             ans.push_back(root->val);
            
//             if(root->left){
//                 st.push(root->left);
//             }
//             if(root->right){
//                 st.push(root->right);
//             }
//         }
        
//         // root , right , left
        
//         reverse(ans.begin(), ans.end());
        
//         // After reverse -> left, right, root
        
//         return ans;

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        
        stack<TreeNode*>st1;
        stack<TreeNode*>st2;
        vector<int>ans;
        if(root==NULL) return ans;
        st1.push(root);
        while(!st1.empty()){
            root=st1.top();
            st1.pop();
            
            st2.push(root);
            if(root->left){
                st1.push(root->left);
            }
            if(root->right){
                st1.push(root->right);
            }
        }
        
        while(!st2.empty()){
            ans.push_back(st2.top()->val);
            st2.pop();
        }
        return ans;
        
    }
};