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
    int lm(TreeNode* root){
        if(root->right)return lm(root->right);
        return root->val;
    }
    int rm(TreeNode* root){
        if(root->left)return rm(root->left);
        return root->val;
    }
    int ans = INT_MIN;
    bool ok(TreeNode* root){
        if(root==NULL)return 1;
        if(root->left){
            if(lm(root->left)>=root->val)return 0;
        }
        if(root->right){
            if(rm(root->right)<=root->val)return 0;
        }
        return 1;
    }
    int fill(TreeNode* root){
        if(root==NULL)return 0;
        int l = fill(root->left);
        int r = fill(root->right);
        ans = max(ans,l);
        ans = max(ans,r);
        if(l==INT_MIN || r==INT_MIN){
            return INT_MIN;
        }
        if(ok(root)){
            ans = max(l+r+root->val,ans);
            cout<<ans<<" ";
            return l+r+root->val;
        }
        return INT_MIN;
    }
public:
    int maxSumBST(TreeNode* root) {
        int temp = fill(root);
        if(ans<0)ans=0;
        return ans;
    }
};