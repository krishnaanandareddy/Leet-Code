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
    vector<string> ans;
    void fill(TreeNode* node, string& temp){
        string a = to_string(node->val);
        int n = a.size();
        if(temp.size()>0){
            temp+="->";
            n=n+2;
        }
        temp+=a;
        if(node->left==NULL && node->right==NULL){
            ans.push_back(temp);
        }
        if(node->left){
            fill(node->left,temp);
        }        
        if(node->right)fill(node->right,temp);
        // cout<<temp<<endl;
        while(n--)temp.pop_back();
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root==NULL)return {};
        string temp = "";
        fill(root, temp);
        return ans;
    }
};