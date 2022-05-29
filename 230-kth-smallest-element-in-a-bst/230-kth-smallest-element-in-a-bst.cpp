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
    void fill(vector<int>& in, TreeNode* t){
        if(t==NULL)return;
        fill(in,t->left);
        in.push_back(t->val);
        fill(in,t->right);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> in;
        fill(in,root);
        return in[k-1];
    }
};