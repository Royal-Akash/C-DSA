/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        
        queue<Node*>q;
        q.push(root);
        if(!root) return root;
        while(!q.empty()){
            
            int size = q.size();
            for(int i=0;i<size;i++){
                // queue<Node*>q1;
                Node* tree = q.front();
                q.pop();
                
                if(tree->left){
                    q.push(tree->left);
                }
                if(tree->right){
                    q.push(tree->right);
                }
                if(!q.empty()){
                    tree->next=q.front();
                }
                if(i==size-1){
                    tree->next=NULL;
                }
            }
            
        }
        return root;
        
    }
};