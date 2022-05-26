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
    void add(TreeNode* t, vector<vector<int>>& ans, int i){
        if(t==NULL)return;
        if(i==ans.size()){
            vector<int> temp;
            ans.push_back(temp);
        }
        ans[i].push_back(t->val);
        add(t->left,ans,i+1);
        add(t->right,ans,i+1);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* t) {
        vector<vector<int>> ans;
        int i = 0;
        add(t,ans,i);
        return ans;
    }
};