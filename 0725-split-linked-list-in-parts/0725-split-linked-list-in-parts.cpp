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
    int countnodes(ListNode* head){
        int count = 0;
        while(head!=NULL){
            head=head->next;
            count++;
        }
        return count;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        
        int count = countnodes(head);
        vector<ListNode*>ans(k);
        if(head==NULL) return ans;
        int split = count/k, left = count%k;
        ListNode* prev = NULL;
        for(int i=0;i<k;i++){
            ans[i]=head;
            for(int j=0;j<split + (i<left);j++){
                prev = head;
                head=head->next;
            }
            prev->next=NULL;
            
        }
        return ans;
        
    }
};