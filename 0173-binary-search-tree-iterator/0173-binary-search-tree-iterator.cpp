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
class BSTIterator {
public:
    stack<TreeNode*>st;
    BSTIterator(TreeNode* root) {
        st.push(root);
        pushall(root);
    }
    
    int next() {
        TreeNode* temp = st.top();
        TreeNode* ans = st.top();
        st.pop();
        if(ans->right){
            st.push(ans->right);
            ans=ans->right;
            pushall(ans);
        }
        return temp->val;
        
    }
    void pushall(TreeNode*root){
        while(root->left){
            st.push(root->left);
            root=root->left;
        }
    }
    
    bool hasNext() {
        return !st.empty()==true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */