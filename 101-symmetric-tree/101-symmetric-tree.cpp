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
    bool check(TreeNode* l, TreeNode* r){
        if(r==NULL && l==NULL)return 1;
        if(r==NULL||l==NULL)return 0;
        if(r->val!=l->val)return 0;
        return (check(l->left,r->right) & check(l->right,r->left));
    }
public:
    bool isSymmetric(TreeNode* root) {
        return check(root->left,root->right);
    }
};