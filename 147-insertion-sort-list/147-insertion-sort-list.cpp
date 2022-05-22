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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *ans = new ListNode(INT_MIN);
        ListNode *anshead = ans;
        ListNode *prev = ans;

        while(head!=NULL){
            ListNode *curr = new ListNode(head->val);
            ListNode *temp = head;
            head = head->next;
            delete temp;
            if(curr->val>=ans->val){
                ans->next = curr;
                ans = ans->next;
            }
            else{
                while(prev->next!=NULL && prev->next->val<curr->val){
                    prev=prev->next;
                }
                ListNode *temp2 = prev->next;
                prev->next = curr;
                curr->next=temp2;
                prev = anshead;
            }
        }
        return anshead->next;       
    }
};