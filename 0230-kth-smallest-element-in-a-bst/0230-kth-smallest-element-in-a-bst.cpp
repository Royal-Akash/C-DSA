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
//     void findin(TreeNode* root, vector<int>&inorder){
        
//         if(root==NULL) return;
//         findin(root->left, inorder);
//         inorder.push_back(root->val);
//         findin(root->right, inorder);
        
//     }
    int kthSmallest(TreeNode* root, int k) {
        // vector<int>inorder;
        // findin(root, inorder);
        // return inorder[k-1];
        if(root==NULL) return -1;
        TreeNode* curr = root;
        int count = 0;
        int ans = -1;
        while(curr!=NULL){
            
            if(curr->left==NULL){
                count++;
                if(count==k){
                    ans=curr->val;
                }
                curr=curr->right;
            }
            else{
                
                TreeNode* prev = curr->left;
                while(prev->right && prev->right!=curr){
                    prev=prev->right;
                }
                if(prev->right==NULL){
                    prev->right=curr;
                    curr=curr->left;
                }
                else{
                    prev->right=NULL;
                    count++;
                    if(count==k){
                        ans = curr->val;
                    }
                    curr=curr->right;
                }
                
            }
            
        }
        return ans;
    }
};