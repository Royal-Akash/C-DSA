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
// class Solution {
// public:
//     vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
//         ListNode* curr = head;
//         int count = 1;
//         while(curr!=NULL){
//             curr=curr->next;
//             count++;
//         }
//         curr=head;
//         vector<ListNode*>ans;
//         if(count<=k){
//             for(int i=0;i<k;i++){
//                 if(curr!=NULL){
//                     ListNode* temp = new ListNode(curr->val);
//                     ans.push_back(temp);
//                     curr=curr->next;
//                 }
//                 else{
//                     ListNode* temp = NULL;
//                     ans.push_back(temp);
//                 }
//             }
//         }
//         else{
//             int sum = count/k;
//             int mod = count%k + sum;
            
//             for(int i=0;i<k;i++){
                
//                 if(ans.empty()){
//                     ListNode* temp = head;
//                     ListNode* sol = temp;
//                     for(int i=0;i<mod;i++){
//                         ListNode* num = new ListNode(curr->val);
//                         temp=num;
//                         temp=temp->next;
//                         curr=curr->next;
//                     }
//                     temp = NULL;
//                     ans.push_back(temp);
//                 }
//                 else if (curr!=NULL){
//                     ListNode* temp = NULL;
//                     for(int j=0;j<sum;j++){
//                         if(curr!=NULL){
//                             ListNode* num = new ListNode(curr->val);
//                             temp=num;
//                             temp=temp->next;
//                             curr=curr->next;
//                         }
//                     }
//                     ans.push_back(temp);
//                 }
//             }
            
//         }
//         return ans;
        
//     }
// };

class Solution {
public:
    int countNodes(ListNode* head) {
        int n = 0;
        while (head) {
            n++;
            head = head->next;
        }
        return n;
    }
    
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = countNodes(head);
        int part_size = n / k, left = n % k;
        ListNode *ptr = head, *prev = NULL;
        
        vector<ListNode*> res(k);
        for (int i = 0; i < k; i++) {
            res[i] = head;
            
            for (int j = 0; j < part_size + (i < left); j++) {
                prev = head; 
                head = head->next; 
            }
            if (prev) prev->next = NULL;
        }
        
        return res;
    }
};