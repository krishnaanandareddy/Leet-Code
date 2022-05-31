/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* A) {
        if(A==NULL)return A;
        Node* prev;
        queue<Node*>q;
        q.push(A);
        Node* ans =A;
        while(q.size()>0){
            int sz=q.size();
            prev=NULL;
            for(int i=0;i<sz;i++){
                Node* temp=q.front();
                q.pop();
                if(prev==NULL){
                    prev=temp;
                }
                else{
                    prev->next=temp;
                    prev=temp;
                }
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            prev->next=NULL;
        }
        return ans;
    }
};