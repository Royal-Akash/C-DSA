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
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> ans;
    if(!root) return ans;
    queue<TreeNode*> q;
    q.push(root);
    int s=q.size();
    // ans.push_back(root->val);
    while(!q.empty()){
        int s=q.size();
        ans.push_back(q.front()->val);
        while(s>0){
            TreeNode* t=q.front();
            q.pop();
            if(t->right) q.push(t->right);
            if(t->left) q.push(t->left);
            s--;
        }
    }
    return ans; 
    }
};