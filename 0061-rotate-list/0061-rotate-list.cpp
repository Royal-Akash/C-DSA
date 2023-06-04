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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head==NULL || head->next==NULL || k==0) return head;
        ListNode* curr = head;
        ListNode* nxt = head ;
        int count = 0;
        while(curr!=NULL){
            
            curr=curr->next;
            count++;
            if(nxt->next!=NULL){
                nxt=nxt->next;
            }
        }
        if(k%count==0) return head;
        curr=head;
        int i = 0;
        if(count>k){
            i=count-k;
        }
        else{
            i=count-k%count;
        }
        while(i!=1){
            curr=curr->next;
            i--;
        }
        ListNode* temp=curr->next;
        nxt->next=head;
        curr->next=NULL;
        return temp;
        
    }
};