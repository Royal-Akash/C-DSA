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
    TreeNode* doWork(vector<int>& nums, int L, int R) {
        if(R < L) return nullptr;
        int M = L + (R-L) / 2;
        
        TreeNode* root = new TreeNode(nums[M]);
        
        root->left = doWork(nums, L, M-1);
        root->right = doWork(nums, M+1, R);
        
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return doWork(nums, 0, n-1);
    }
};