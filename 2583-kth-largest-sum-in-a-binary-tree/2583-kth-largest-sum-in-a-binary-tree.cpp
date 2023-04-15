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
// class Solution {
// public:
//     long long kthLargestLevelSum(TreeNode* root, int k) {
//         priority_queue<long long>pq;
//         queue<TreeNode*>q;
//         q.push(root);
//         while(!q.empty()){
            
//             int size = q.size();
//             long long sum = 0;
            
//             for(int i=0;i<size;i++){
                
//               TreeNode* node = q.front();
//                 q.pop();
//                 sum+=node->val;
//                 if(node->left){
//                     q.push(node->left);
//                 }
//                 if(node->right){
//                     q.push(node->right);
//                 }
//             }
//             pq.push(sum);
//         }
//         if(k>pq.size()){
//             return -1;
//         }
//         else{
//             for(int i=0;i<k-1;i++){
//                 pq.pop();
//             }
//         }
        
//         return pq.top();
        
//     }
// };

class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        
        queue<TreeNode*> q;
        q.push(root);
        int cnt = 0;
        
        while(!q.empty()) {
            long long n = q.size(), s = 0;
            
            while(n--) {
                TreeNode* temp = q.front(); q.pop();
                s += temp -> val;
                
                if(temp -> left) q.push(temp -> left);
                if(temp -> right) q.push(temp -> right);
            }
            cnt++;
            pq.push(s);
            if(pq.size() > k) pq.pop();
        }
        
        return cnt < k ? -1 : pq.top();
    }
};