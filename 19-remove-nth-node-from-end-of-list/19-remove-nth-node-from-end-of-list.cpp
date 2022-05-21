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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode *temp = head;
        while(temp!=NULL){
            temp=temp->next;
            size++;
        }
        int pos = size+1-n;
        temp = head;
        int cp = 1;
        if(pos==1)return head->next;
//         identifying the correct basecase is very important think it for all edge cases
        while(cp<pos-1){
            cp++;
            temp=temp->next;
        }
        ListNode *t = temp->next;
        temp->next=temp->next->next;
        delete t;
        return head;
    }
};