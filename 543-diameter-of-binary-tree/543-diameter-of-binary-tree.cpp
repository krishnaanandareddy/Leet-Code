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
    int d(TreeNode* t,int &ans){
        if(t==NULL)return 0;
        int lh = d(t->left,ans);
        int rh = d(t->right,ans);
        if(lh+rh>ans){
            ans=lh+rh;
        }
        return max(lh,rh)+1;
    }
public:
    int diameterOfBinaryTree(TreeNode* t) {
        int ans = 0;
        int temp = d(t,ans);
        return ans;
    }
};