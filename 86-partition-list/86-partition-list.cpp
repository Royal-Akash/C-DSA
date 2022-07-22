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
    ListNode* partition(ListNode* head, int x) {
        
//         ListNode *SmallHead = new ListNode(0);
//         ListNode *LargeHead = new ListNode(0);
        
//         ListNode *Small = SmallHead , *Large = LargeHead;
        
//         while(head!=NULL){
            
//             if(head->val<x){
//                 Small->next = head;
//                 Small = Small->next;
//             }
//             else{
//                 Large->next = head;
//                 Large = Large->next;
//             }
//             head = head ->next;
            
//         }
//         Large->next = NULL;
//         Small->next = LargeHead->next;
//         return SmallHead->next;
        
        ListNode * smallHead = new ListNode(0);
        ListNode * largeHead = new ListNode(0);
        
        ListNode * small = smallHead , *large = largeHead;
        
        while(head!=NULL){
            
            if(head->val<x){
                small->next=head;
                small = small->next;
            }
            else{
                
                large->next=head;
                large=large->next;
                
            }
            head=head->next;
        }
        large->next=NULL;
        
        small->next = largeHead->next;
        return smallHead->next;
    }
};