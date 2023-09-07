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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        ListNode* temp = head;
        ListNode* prev1 = head;
        int z = left;
        while(z>1){
            prev1=temp;
            temp=temp->next;
            z--;
        }
        // cout<<temp->val<<endl;
        ListNode* prev = temp;
        ListNode* num = temp;
        ListNode* num1 = num->next;
        int k = right-left;
        while(k>0){
            ListNode*num2 = num1->next;
            num1->next=num;
            num=num1;
            num1=num2;
            k--;
        }
        // cout<<num->val<<endl;
        prev1->next=num;
        prev->next=num1;
        
        if(left==1) return num;
        
        return head;
        
    }
};