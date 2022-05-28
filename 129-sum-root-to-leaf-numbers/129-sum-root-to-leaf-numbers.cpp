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
    void a(TreeNode* t, string& curr, int& ans){
        if(t==NULL)return;
        curr+='0'+t->val;
        if(t->left==NULL && t->right==NULL){
            ans+=stoi(curr);
        }
        if(t->left!=NULL){
            a(t->left,curr,ans);
        }
        if(t->right!=NULL){
            a(t->right,curr,ans);
        }
        curr.pop_back();
    }    
public:
    int sumNumbers(TreeNode* A) {
        string curr;
        int ans = 0;
        a(A,curr,ans);
        return ans;       
        
    }
};