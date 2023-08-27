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
    int amountOfTime(TreeNode* root, int start) {
        
        if(root==NULL) return 0;
        TreeNode* node=root;
        
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty()){
            node=st.top();
            st.pop();
            if(node->val==start) break;
            if(node->left){
                st.push(node->left);
            }
            if(node->right){
                st.push(node->right);
            }
        }
        return distanceK(root, node);
        
    }
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
    int distanceK(TreeNode* root, TreeNode* target) {
        
        unordered_map<TreeNode*, TreeNode*>mp;
        parent(root, mp);
        vector<int>ans;
        unordered_map<TreeNode*, bool>vis;
        queue<TreeNode*>q;
        q.push(target);
        vis[target]=true;
        int count=0;
        while(!q.empty()){
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
        return count-1;
        
    }
};