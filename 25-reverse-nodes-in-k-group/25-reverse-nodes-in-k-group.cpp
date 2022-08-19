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
//     ListNode* reverseKGroup(ListNode* head, int k) {
        
//         if(head==NULL || k==1) return head;
        
//         ListNode * dummy= new ListNode(0);
//         dummy->next=head;
        
//         ListNode * curr = dummy , *pre = dummy , *nex = dummy;
//         int count=0;
//         while(curr->next!=NULL){
//             curr=curr->next;
//             count++;
//         }
        
//         while(count>=k){
            
//             curr = pre->next;
//             nex = curr->next;
//             for(int i=1;i<k;i++){
                
//                 curr->next=nex->next;
//                 nex->next=pre->next;
//                 pre->next=nex;
//                 nex=curr->next;
                
//             }
//             pre=curr;
//             count-=k;
                
            
//         }
//         return dummy->next;
//     }
    
//     ListNode* reverseKGroup(ListNode* head, int k) {
//         //check for empty list
//         if( head == NULL || k==1){
//             return head;
//         }
        
//         //step 1 reverse first k group in ITERATIVE WAY
//         ListNode* tiny = new ListNode(0);
//         tiny->next=head;
//         ListNode* prev = tiny;
//         ListNode* curr = tiny;
//         ListNode* forward = tiny;
//         int count = 0;
        
//         while(curr->next!=NULL){
//             curr=curr->next;
//             count++;
//         }
//         while(count>=k){
            
//             curr=prev->next;
//             forward=curr->next;
            
//             for(int i=0;i<k;i++){
//                 forward = curr->next;
//                 curr->next = prev;
//                 prev = curr;
//                 curr = forward;
//              }
//             count-=k;
//         }
        
//         // if(count>k && forward != NULL){
//         //      head->next = reverseKGroup(forward,k);
//         // }
//         //s2 call recursion 
//         // if(forward != NULL){
//         //     head->next = reverseKGroup(forward,k);
//         // }
//         //s3 return updated head for our LL
//         return prev;
//     }
// };

    	ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cursor = head;
        for(int i = 0; i < k; i++){
            if(cursor == nullptr) return head;
            cursor = cursor->next;
        }
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* forward = nullptr;
        for(int i = 0; i < k; i++){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        head->next = reverseKGroup(curr, k);
        return prev;
    }
};