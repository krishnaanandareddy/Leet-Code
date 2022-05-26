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
    void fill(TreeNode* t, map<int,int>& m, int r){
        if(t==NULL)return;
        m[r]=t->val;
        fill(t->left,m,r+1);
        fill(t->right,m,r+1);
    }
public:
    vector<int> rightSideView(TreeNode* t) {
        map<int,int> m;
        fill(t,m,0);
        vector<int> ans;
        for(auto i:m){
            ans.push_back(i.second);
        }
        return ans;
    }
};