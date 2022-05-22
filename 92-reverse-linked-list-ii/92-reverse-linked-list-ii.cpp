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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *temp = new ListNode(0);
        int curr = 0;
        temp->next = head;
        ListNode *ans = temp;
        while(temp!=NULL){
            curr++;
            ListNode *prev = temp;
            temp = temp->next;
            if(curr==m){
                ListNode *part = new ListNode(temp->val);
                ListNode *partend = part;

                for(int i=m+1;i<=n;i++){
                    temp = temp->next;
                    ListNode *temp2 = new ListNode(temp->val);
                    temp2->next = part;
                    part = temp2;
                }
                prev->next = part;
                partend->next = temp->next;
            }
        }
        return ans->next;
        
    }
};