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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry =0;
        ListNode *sum = new ListNode(0);
        ListNode *ans = sum;
        while(l1!=NULL &&l2!=NULL){
            int temp = l1->val+l2->val+carry;
            if(temp>=10){
                temp-=10;
                carry=1;
            }
            else{
                carry=0;
            }
            ListNode *newnode = new ListNode(temp);
            sum->next=newnode;
            sum=sum->next;
            l1=l1->next;
            l2=l2->next;
        }
        if(l2 || l1){
            if(l2)l1=l2;
            while(l1!=NULL){
                int temp=l1->val+carry;
                if(temp>=10){
                    temp-=10;
                    carry=1;
                }
                else{
                    carry=0;
                }
                ListNode *newnode = new ListNode(temp);
                sum->next=newnode;
                sum=sum->next;
                l1=l1->next;
            }
        }
        if(carry==1){                
            ListNode *newnode = new ListNode(1);
            sum->next=newnode;
        }
        return ans->next;
    }
};