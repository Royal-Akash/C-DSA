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
// class Solution {
// private:
//     void preorder(TreeNode*root , vector<int>&v){
//         if (root == NULL){
//             v.push_back(0);
//             return;
//         }

//         preorder(root->left , v);

//         v.push_back(root->val);

//         preorder(root->right , v);
//     }
// public:
//     bool isSameTree(TreeNode* p, TreeNode* q) {
//         vector<int>v1 , v2;
//         preorder(p , v1);
//         preorder(q , v2);
        
//         return v1==v2;
//     }
// };

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        if(p==NULL || q==NULL) return (p==q);

        return (p->val==q->val)
       && isSameTree(p->left , q->left)
       && isSameTree(p->right , q->right);

    }
};