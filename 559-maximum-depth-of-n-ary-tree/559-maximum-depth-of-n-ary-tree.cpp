/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        int ans = 0;
        queue<Node*>q;
        if(root==NULL)return ans;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            ans++;
            for(int i=0;i<n;i++){
                Node* nod = q.front();
                q.pop();
                for(auto i: nod->children){
                    q.push(i);
                }
            }
        }
        return ans;
    }
};