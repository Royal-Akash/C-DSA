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
class BSTIterator{
    stack<TreeNode*>st;
    bool flag = true;
public:
    
    BSTIterator(TreeNode*root, bool direction){
        flag=direction;
        st.push(root);
        pushall(root);
    }
    
    int next(bool direction){
        TreeNode*temp = st.top();
        TreeNode*ans = st.top();
        st.pop();
        if(direction==false && ans->right){
            st.push(ans->right);
            ans=ans->right;
            pushall(ans);
        }
        else if(direction==true && ans->left){
            st.push(ans->left);
            ans=ans->left;
            pushall(ans);
        }
        return temp->val;
    }
    
    void pushall(TreeNode* root){
        if(flag==true){
            while(root->right){
                st.push(root->right);
                root=root->right;
            }
        }
        else{
            while(root->left){
                st.push(root->left);
                root=root->left;
            }
        }
    }
    
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL) return false;
        BSTIterator l(root, false);
        BSTIterator r(root, true);
        
        int left = l.next(false);
        int right = r.next(true);
        while(left<right){
            if(left+right==k) return true;
            else if(left+right<k){
                left = l.next(false);
            }
            else{
                right = r.next(true);
            }
        }
        return false;
    }
};