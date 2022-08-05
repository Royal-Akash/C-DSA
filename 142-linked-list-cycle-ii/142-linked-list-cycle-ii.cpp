/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
//         unordered_set<ListNode*> s;
//         ListNode*temp = head;
        
//         while(temp!=NULL){
            
//             if(s.find(temp)==s.end()){
                
//                 s.insert(temp);
                
//             }
//             else{
//                 return temp;
//             }
            
//             temp=temp->next;
//         }
//         return NULL;
        
        
        if(head==NULL || head->next==NULL) return NULL;
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* entry = head;
        
        while(fast->next!=NULL && fast->next->next!=NULL){
            
            slow=slow->next;
            fast=fast->next->next;
            
            if(fast==slow){
                
                while(slow!=entry){
                    entry=entry->next;
                    slow=slow->next;
                }
                return entry;
            }
        }
        return NULL;
        
    }
};