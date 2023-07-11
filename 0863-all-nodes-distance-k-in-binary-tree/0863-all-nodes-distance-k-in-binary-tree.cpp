/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void findparent(TreeNode* root,unordered_map<TreeNode* , TreeNode*>&parent,int k)
    {
        queue<TreeNode*>q;
        q.push(root);
        // TreeNode* curr=root;
        while(!q.empty()){

            TreeNode* curr=q.front();
            q.pop();
            if(curr->left){
                parent[curr->left]=curr;
                q.push(curr->left);
            }
            if(curr->right){
                parent[curr->right]=curr;
                q.push(curr->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        unordered_map<TreeNode* , TreeNode*>parent;
        findparent(root , parent , k);

        unordered_map<TreeNode* , bool>visited;
        queue<TreeNode*>q;
        int currTrack=0;
        q.push(target);
        visited[target]=true;
        
        while(!q.empty()){

            int size=q.size();
            if(currTrack++==k) break;
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left && !visited[node->left]){
                    q.push(node->left);
                    visited[node->left]=true;
                }
                if(node->right && !visited[node->right]){
                    q.push(node->right);
                    visited[node->right]=true;
                }
                if(parent[node] && !visited[parent[node]]){
                    q.push(parent[node]);
                    visited[parent[node]]=true;
                }
            }
        }

        vector<int>ans;
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            ans.push_back(node->val);
        }
        return ans;

    }
};