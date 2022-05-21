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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1== NULL)return l2;
        if(l2==NULL)return l1;
        // (new key word allocates space so it retuen a pointer)
        ListNode* ans = new ListNode(10);
        ListNode* head = ans;
        while(l1!=NULL && l2!=NULL){
            if(l1->val>l2->val){
                ListNode *nnode = new ListNode(l2->val);
                ans->next = nnode;
                ans = ans->next;
                l2=l2->next;
            }
            else{
                ListNode *nnode = new ListNode(l1->val);
                ans->next = nnode;
                l1=l1->next;
                ans = ans->next;
            }
        }
        if(l1!=NULL)ans->next=l1;
        if(l2!=NULL)ans->next=l2;
        return head->next;
    }
};