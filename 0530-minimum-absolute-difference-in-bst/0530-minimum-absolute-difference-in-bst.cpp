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
    int mini=INT_MAX;
    void Minimum(TreeNode *root,vector<int>& sorted)
    {
        if(root)
        {
            Minimum(root->left,sorted);
            sorted.push_back(root->val);
            Minimum(root->right,sorted);
        }
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int> sorted;
        Minimum(root,sorted);
        for(int i=1;i<sorted.size();i++)
        {
            mini=min(mini,(sorted[i]-sorted[i-1]));
        }
        return mini;
    }
};