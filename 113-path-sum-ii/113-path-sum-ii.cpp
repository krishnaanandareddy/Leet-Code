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
    void fill(TreeNode* t, int sum, int cs, vector<int>& temp, vector<vector<int>>& ans){
        if(t==NULL)return;
        cs+=t->val;
        temp.push_back(t->val);
        if(t->left==NULL && t->right==NULL){
            if(cs==sum){
                ans.push_back(temp);
            }
        }
        if(t->left!=NULL){
            fill(t->left,sum,cs,temp,ans);
        }
        if(t->right!=NULL){
            fill(t->right,sum,cs,temp,ans);
        }
        temp.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* t, int sum) {
        vector<int> temp;
        vector<vector<int>> ans;
        fill(t,sum,0,temp,ans);
        return ans;
    }
};