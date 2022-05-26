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
    void add(vector<vector<int>>& ans, int i, TreeNode* t){
        if(t==NULL)return;
        if(ans.size()==i){
            vector<int> temp;
            ans.push_back(temp);
        }
        ans[i].push_back(t->val);
        add(ans,i+1,t->left);
        add(ans,i+1,t->right);
    }
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* t) {
        vector<vector<int>> ans;
        int i =0;
        add(ans,i,t);
        for(int i=0;i<ans.size();i++){
            if(i%2){
                reverse(ans[i].begin(),ans[i].end());
            }
        }
        return ans;
    }
};