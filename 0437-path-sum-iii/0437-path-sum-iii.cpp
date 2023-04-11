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
    unordered_map<long, int> mp;
    int count=0;
private:
    void countpath(TreeNode* root, int targetSum, long sum){
        if(!root) return;
        
        sum+=root->val;
        if(sum==targetSum) count++;
        
        if(mp.count(sum-targetSum)){
            count+=mp[sum-targetSum];
        }
        mp[sum]++;
        
        countpath(root->left, targetSum, sum);
        countpath(root->right, targetSum, sum);
        mp[sum]--;
        
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        
        countpath(root, targetSum, 0);
        return count;
        
    }
};