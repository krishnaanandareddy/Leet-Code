/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    TreeNode* find(TreeNode* t, TreeNode* p, TreeNode* q, bool pf, bool qf){
        if(t==NULL)return NULL;
        TreeNode* temp1 = find(t->left,p,q,pf,qf);
        TreeNode* temp2 = find(t->right,p,q,pf,qf);
        if(temp1!=NULL && temp2 != NULL)return t;
        if(t==p){
            return t;
        }
        if(t==q){return t;
        }
        if(temp1!=NULL)return temp1;
        if(temp2!=NULL)return temp2;
        return NULL;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* t, TreeNode* p, TreeNode* q) {
        return find(t,p,q,0,0);
    }
};