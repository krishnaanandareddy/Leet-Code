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
public:
    vector<int> postorderTraversal(TreeNode* t) {
        stack<TreeNode*>s;
        vector<int> ans;
        if(t==NULL)return ans;
        s.push(t);
        while(!s.empty()){
            TreeNode* temp = s.top();
            s.pop();
            ans.push_back(temp->val);
            if(temp->left!=NULL)s.push(temp->left);
            if(temp->right!=NULL)s.push(temp->right);
        }
        reverse(ans.begin(),ans.end());
        return ans;        
        
    }
};