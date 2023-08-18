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

// Recursion
// void findinorder(TreeNode* root, vector<int>&ans){
//         if(root==NULL) return;
        
//         findinorder(root->left, ans);
//         ans.push_back(root->val);
//         findinorder(root->right, ans);
//     }
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int>ans;
//         findinorder(root, ans);
//         return ans;
//     }

// Iterative approach
//         stack<TreeNode*> st;
//         vector<int>ans;
//         TreeNode*node = root;
        
//         while(true){
            
//             if(node!=NULL){
//                 st.push(node);
//                 node=node->left;
//             }
//             else{
//                 if(st.empty()) break;
                
//                 node = st.top();
//                 st.pop();
//                 ans.push_back(node->val);
//                 node=node->right;
//             }
            
//         }
//         return ans;
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int>ans;
        if(root==NULL) return ans;
        
        TreeNode*curr = root;
        while(curr!=NULL){
        
            if(curr->left==NULL){
                ans.push_back(curr->val);
                curr=curr->right;
            }
            else{
                
                TreeNode*prev=curr->left;
                while(prev->right && prev->right!=curr){
                    prev=prev->right;
                }
                if(prev->right==NULL){
                    prev->right=curr;
                    curr=curr->left;
                }
                else{
                    prev->right=NULL;
                    ans.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
        return ans;
    }
};