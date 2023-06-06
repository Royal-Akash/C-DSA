/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void copylist(Node* head){
        
        Node* temp = head;
        Node* n = head->next;
        while(temp!=NULL){
            
            Node* copy = new Node(temp->val);
            temp->next = copy;
            copy->next=n;
            temp=n;
            if(n!=NULL){
                n=n->next;;
            }
        }
    }
    void addrandom(Node* head){
        
        Node* temp = head;
        while(temp!=NULL){
            
            if(temp->random!=NULL){
                temp->next->random=temp->random->next;
            }
            temp=temp->next->next;
            
        }
        
    }
    Node* detechlist(Node* head){
        
        Node* temp= head;
        Node* dummy = new Node(-1);
        Node* n = dummy;
        while(temp!=NULL){
            
            n->next=temp->next;
            n=n->next;
            temp->next=n->next;
            temp=temp->next;
            
        }
        return dummy->next;
    }
    
    Node* copyRandomList(Node* head) {
        
//         map<Node*, Node*>mp;
//         Node*temp = head;
//         while(temp!=NULL){
//             Node* copy = new Node(temp->val);
//             mp[temp]=copy;
//             temp=temp->next;
//         }
        
//         temp = head;
//         while(temp!=NULL){
//             mp[temp]->next=mp[temp->next];
//             mp[temp]->random=mp[temp->random];
//             temp=temp->next;
//         }
//         return mp[head];
        
        if(head==NULL) return NULL;
        copylist(head);
        addrandom(head);
        return detechlist(head);
        
    }
};