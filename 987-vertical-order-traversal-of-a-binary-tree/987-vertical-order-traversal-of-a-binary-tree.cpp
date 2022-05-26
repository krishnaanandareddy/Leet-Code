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
    void fill(TreeNode* t, map<int,vector<pair<int,int>>>& m, int c,int r){
        if(t==NULL)return;
        m[c].push_back({r,t->val});
        fill(t->left,m,c-1,r+1);
        fill(t->right,m,c+1,r+1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* t) {
        map<int,vector<pair<int,int>>> m;        
        fill(t,m,0,0);
        vector<vector<int>> ans;
        for(auto v:m){
            vector<int> temp;
            sort(v.second.begin(),v.second.end());
            for(auto i:v.second){
                temp.push_back(i.second);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};