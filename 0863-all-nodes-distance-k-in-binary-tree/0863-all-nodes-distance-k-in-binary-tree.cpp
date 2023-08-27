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
    void parent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>&mp){
        
        if(root==NULL) return;
        
        if(root->left){
            mp[root->left]=root;
            parent(root->left, mp);
        }
        if(root->right){
            mp[root->right]=root;
            parent(root->right, mp);
        }
        
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        unordered_map<TreeNode*, TreeNode*>mp;
        parent(root, mp);
        vector<int>ans;
        unordered_map<TreeNode*, bool>vis;
        queue<TreeNode*>q;
        q.push(target);
        vis[target]=true;
        int count=0;
        while(!q.empty()){
            if(count==k) break;
            int n = q.size();
            for(int i=0;i<n;i++){
                
                TreeNode* node = q.front();
                q.pop();
                if(node->left && !vis[node->left]){
                    q.push(node->left);
                    vis[node->left]=true;
                }
                if(node->right && !vis[node->right]){
                    q.push(node->right);
                    vis[node->right]=true;
                }
                if(mp[node] && !vis[mp[node]]){
                    q.push(mp[node]);
                    vis[mp[node]]=true;
                }
                
            }
            count++;
        }
        
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
        
    }
};