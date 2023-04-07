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
private:
    int maxdepth(TreeNode* root){
        if(root==NULL) return 0;
        
        int lf = maxdepth(root->left);
        int rt = maxdepth(root->right);
        
        return 1+max(lf , rt);
        
    }
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        int size = maxdepth(root);
        vector<vector<int>>level(size);
        size--;
        if(root==NULL) return level;
        queue<TreeNode*>q;
        q.push(root);
        int j=0;
        while(!q.empty()){
            vector<int>ans;      
            int size1 = q.size();
            for(int i=0;i<size1;i++){
                TreeNode*curr = q.front();
                q.pop();
                ans.push_back(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                
            }
            // level[size-1-j].insert(level[size-1-j].begin(), ans.begin(), ans.end());
            level[size--]=ans;
            j++;
            
        }
        return level;
        
    }
};