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
    void find(TreeNode* root, int &maxi, unordered_map<int, int>&mp){
        
        if(root==NULL) return;
        int num = root->val;
        mp[num]++;
        maxi = max(maxi, mp[num]);
        if(root->left) find(root->left, maxi, mp);
        if(root->right) find(root->right, maxi, mp);
        
        
    }
    vector<int> findMode(TreeNode* root) {
        vector<int>ans;
        unordered_map<int, int>mp;
        int maxi = INT_MIN;
        find(root, maxi, mp);
        for(auto it:mp){
            if(it.second==maxi){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};