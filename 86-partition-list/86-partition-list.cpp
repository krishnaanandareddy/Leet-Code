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
        ListNode *ans1 = new ListNode(1);
        ListNode *ans2 = new ListNode(1);
        ListNode *head1 = ans1;
        ListNode *head2 = ans2;

        while(head!=NULL){
            if(head->val<x){
                ListNode *newnode = new ListNode(head->val);
                ans1->next = newnode;
                ans1=ans1->next;
            }
            else{
                ListNode *newnode = new ListNode(head->val);
                ans2->next = newnode;
                ans2=ans2->next;            
            }
            head=head->next;
        }
        ans1->next = head2->next;
        return head1->next;
        
    }
};