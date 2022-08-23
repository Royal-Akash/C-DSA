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
    
    ListNode * reverse(ListNode* head){
        ListNode * curr=head;
        ListNode * prev = NULL;
        ListNode * forw = NULL;
        while(curr!=NULL){
            forw = curr->next;
            curr->next = prev;
            prev=curr;
            curr=forw;
         }
            return prev;
        }
    bool isPalindrome(ListNode* head) {
        
        if(head==NULL || head->next==NULL) return true;
        ListNode*slow = head;
        ListNode * fast = head;
        
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=reverse(slow->next);
        slow=slow->next;
        
        while(slow!=NULL){
            if(head->val!=slow->val) return false;
            else{
                head=head->next;
                slow=slow->next;
            }
        }
        return true;
      }
};      
        

        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
//         // curr=prev;
//         // while(prev!=NULL){
//         //     cout<<prev->val;
//         //     prev=prev->next;
//         // }cout<<endl;
//         // prev=curr;
//         // curr=head;
        
//         while(full!=NULL){
            
//             if(full->val!=prev->val){
//                 return false;
//                 break;
//             }
//             else{
//                 full=full->next;
//                 prev=prev->next;
//             }
//         }
//         return true;
