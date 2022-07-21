/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)return NULL;
        Node* prev = NULL;
        Node *head2 = NULL;
        Node *temp = head;
        unordered_map<Node*,Node*> m;
        while(temp){
            Node *tn = new Node(temp->val);
            if(prev){
                prev->next = tn;
            }
            else{
                head2 = tn;
            }
            m[temp] = tn;
            prev = tn;
            temp = temp->next;
        }
        temp = head;
        Node* temp2 = head2;
        while(temp){
            temp2->random = NULL;
            if(temp->random)temp2->random = m[temp->random];
            // cout<<m[temp->random]->val;
            temp = temp->next;
            temp2 = temp2->next;
        }
        return head2;
    }
};