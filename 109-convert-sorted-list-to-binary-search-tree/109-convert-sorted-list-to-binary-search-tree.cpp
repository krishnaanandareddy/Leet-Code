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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL)return NULL;
        int n = 0;
        ListNode* temp = head;
        while(temp){
            n++;
            temp=temp->next;
        }
        int mid = n/2+n%2;
        temp = head;
        ListNode* prev = NULL;
        int pos = 0;
        TreeNode* root;
        while(temp){
            pos++;
            if(pos==mid){
                int val = temp->val;
                cout<<val<<" ";
                root=new TreeNode(val);
                if(prev)prev->next=NULL;
                ListNode* temp2 = temp->next;
                temp->next = NULL;
                temp = temp2;
                break;
            }
            prev = temp;
            temp = temp->next;
        }
        if(prev == NULL)head = NULL;
        TreeNode* r = sortedListToBST(head);
        TreeNode* l = sortedListToBST(temp);
        root->right = l;
        root->left = r;
        return root;
    }
};