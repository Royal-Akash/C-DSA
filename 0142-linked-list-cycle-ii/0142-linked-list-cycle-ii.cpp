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
        
        ListNode * fast = head, *slow = head, *newList=NULL;
        if(head==NULL || head->next==NULL) return newList;
        
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            
            if(fast==slow) break;
        }
        slow = head;
        if(fast==NULL || fast->next==NULL) return newList;
        else{
            while(slow!=fast){
                fast=fast->next;
                slow=slow->next;
            }
            newList = fast;}
        return newList;
    }
};