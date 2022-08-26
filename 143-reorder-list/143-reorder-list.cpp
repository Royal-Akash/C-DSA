/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        
        stack<ListNode*> st;
        ListNode* fast = head;
        // ListNode* slow = head;
        ListNode* dummy = head;
        ListNode* prev = NULL;
        ListNode* curr = head;
        
        if(!head) return;
        
        while(fast->next!=NULL && fast->next->next!=NULL){
            // slow=slow->next;
            dummy=dummy->next;
            fast=fast->next->next;
        }
        // slow->next=NULL;
        while(dummy!=NULL){
            st.push(dummy);
            dummy=dummy->next;
        }
        while(!st.empty()){
            ListNode* ele = st.top();
            st.pop();
            if(curr==ele){
                break;
            }
            prev=curr->next;
            curr->next=ele;
            ele->next=prev;
            curr=prev;
            
        }
        curr->next=NULL;
        // return head;
    }
};