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
    ListNode* reverseList(ListNode* head) {
        // ListNode* prev = NULL, curr = head, nxt = head->next; WRITNG THIS WAY IS WRONG
        ListNode *prev = NULL, *curr = head, *nxt = head; 
        while(curr!=NULL){
            nxt = nxt->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
};