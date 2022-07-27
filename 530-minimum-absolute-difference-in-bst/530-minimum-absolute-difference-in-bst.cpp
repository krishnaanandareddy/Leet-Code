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
    void fill(TreeNode * root){
        if(root==NULL)return ;
        fill(root->left);
        in.push_back(root->val);
        fill(root->right);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        fill(root);
        int n = in.size();
        int ans = INT_MAX;
        for(int i=1;i<n;i++){
            ans = min(ans,abs(in[i]-in[i-1]));
        }
        return ans;
    }
};