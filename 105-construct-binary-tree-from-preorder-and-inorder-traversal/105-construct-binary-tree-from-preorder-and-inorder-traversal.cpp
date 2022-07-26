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
    TreeNode* build(vector<int>& pre, int ps, int pe, vector<int>& in, int is, int ie,  unordered_map<int,int>& m){
        if(ps>pe || is>ie)return NULL;
        TreeNode* root = new TreeNode(pre[ps]);
        int rpos = m[pre[ps]];
        int nleft = rpos-is;
        int nright = ie-rpos;
        TreeNode * left = build(pre,ps+1,ps+nleft,in,is,is+nleft-1,m);
        TreeNode * right = build(pre,ps+nleft+1,pe,in,ie-nright+1,ie,m);
        root->left = left;
        root->right = right;
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        unordered_map<int,int> m;
        int n = in.size();
        for(int i=0;i<n;i++){
            m[in[i]]=i;
        }
        return build(pre,0,n-1,in,0,n-1,m);
    }
};