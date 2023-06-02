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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode * node = new ListNode();
        ListNode * add = node;
        int carry = 0, data = 0;
        while(l1!=NULL || l2!=NULL || carry>0){
            ListNode * dum = new ListNode();
            int sum =0;
            if(l1!=NULL){ 
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){ 
                sum+=l2->val;
                l2=l2->next;
            }
            
            sum+=carry;
            carry=0;
            data =0;
            if(sum>=10){
                carry=sum/10;
                data = sum%10;
                dum->val=data;
            }
            else{
                dum->val=sum;
            }
            node->next=dum;
            node=node->next;
        }
        // node=add;
        return add->next;
    }
};