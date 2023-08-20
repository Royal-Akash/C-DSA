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
#include<bits/stdc++.h>
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL) return ans;
        map<int, map<int, multiset<int>>>mp;
        stack<pair<TreeNode*, pair<int, int>>>st;
        st.push({root, {0, 0}});
        
        while(!st.empty()){
            auto it = st.top();
            st.pop();
            TreeNode* node = it.first;
            int lineV = it.second.second;
            int lineH = it.second.first;
            mp[lineV][lineH].insert(node->val);
            if(node->left){
                st.push({node->left, {lineH+1, lineV-1}});
            }
            if(node->right){
                st.push({node->right,{lineH+1, lineV+1}});
            }
            
        }
        for(auto it:mp){
            vector<int>col;
            for(auto q:it.second){
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};