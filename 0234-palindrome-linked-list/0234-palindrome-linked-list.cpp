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
private:
    ListNode* reverselist(ListNode *head){
        ListNode * newlist = NULL;
        while(head!=NULL){
            ListNode*nxt = head->next;
            head->next = newlist;
            newlist=head;
            head=nxt;
        }
        
        return newlist;
        
    }
public:
    bool isPalindrome(ListNode* head) {
        
        if(head==NULL || head->next==NULL) return true;
        ListNode* fast = head;
        ListNode* slow = head;
        
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        slow->next = reverselist(slow->next);
        slow=slow->next;
        fast = head;
        
        while(slow!=NULL){
            if(fast->val!=slow->val){
                return false;
                break;
            }
            fast=fast->next;
            slow=slow->next;
        }
        return true;
        
    }
};