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
    vector<int> in;
    void fill(TreeNode* root){
        if(root==NULL)return;
        if(root->left)fill(root->left);
        in.push_back(root->val);
        if(root->right)fill(root->right);
    }
public:
    bool isValidBST(TreeNode* root) {
        fill(root);
        int n  = in.size();
        for(int i=1;i<n;i++){
            if(in[i]<=in[i-1])return 0;
        }
        return 1;
    }
};