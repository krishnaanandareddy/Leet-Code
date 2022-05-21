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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL)return head;
        ListNode *temp=head->next,*prev=head;
        while(temp!=NULL){
            if(temp->val==prev->val){
                prev->next=temp->next;
                ListNode *temp2 = temp;
                temp=temp->next;
                delete temp2;
            }
            else{
                prev=prev->next;
                temp=temp->next;
            }
        }
        return head;
    }
};