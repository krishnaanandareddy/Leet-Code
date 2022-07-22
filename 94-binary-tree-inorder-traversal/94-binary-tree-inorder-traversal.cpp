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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> ans;
        TreeNode* node = root;
        while(1){
            if(node!=NULL){
                s.push(node);
                node=node->left;
            }
            else{
                if(s.empty())return ans;
                node = s.top();
                ans.push_back(node->val);
                s.pop();
                node=node->right;
            }
        }
    }
};