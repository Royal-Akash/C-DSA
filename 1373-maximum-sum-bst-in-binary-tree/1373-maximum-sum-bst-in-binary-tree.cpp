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
class Nodevalue{
public:
    int maxvalue, minvalue, maxsum;
    Nodevalue(int minvalue, int maxvalue, long long maxsum){
        this->minvalue=minvalue;
        this->maxvalue=maxvalue;
        this->maxsum=maxsum;
    }    
};
class Solution {
private:
    int ans=0;
    Nodevalue greatestsum(TreeNode*root){
        
        
        if(!root){
            return Nodevalue(INT_MAX, INT_MIN, 0);
        }
        auto left = greatestsum(root->left);
        auto right = greatestsum(root->right);
        
        if(left.maxvalue<root->val && right.minvalue>root->val){
            ans = max(ans, left.maxsum+right.maxsum+root->val);
            return Nodevalue(min(root->val, left.minvalue), max(root->val, right.maxvalue), left.maxsum+right.maxsum+root->val);
        }
        return Nodevalue(INT_MIN, INT_MAX, max(left.maxsum, right.maxsum));
    }
public:
    int maxSumBST(TreeNode* root) {
        greatestsum(root);  
        return ans;
    }
};