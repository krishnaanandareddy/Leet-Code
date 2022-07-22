/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode *,TreeNode*>m;
        stack<TreeNode*> s;
        if(root==NULL)return {};
        s.push(root);
        m[root]=NULL;
        while(!s.empty()){
            TreeNode* temp = s.top();
            s.pop();
            if(temp->left){
                m[temp->left] = temp;
                s.push(temp->left);
            }
            if(temp->right){
                m[temp->right] = temp;
                s.push(temp->right);
            }
        }
        queue<TreeNode*> q;
        q.push(target);
        int dis=0;
        vector<int> ans;
        unordered_map<TreeNode*,int> vis;
        while(!q.empty()){
            if(dis>k)break;
            int n = q.size();
            while(n--){
                TreeNode* node = q.front();
                q.pop();
                if(vis[node]==1)continue;
                if(dis>k)break;
                if(dis==k)ans.push_back(node->val);
                vis[node]=1;
                if(node->left && vis[node->left]!=1){
                    q.push(node->left);
                }
                if(node->right && vis[node->right]!=1){
                    q.push(node->right);
                }
                if(m[node]&&vis[m[node]]!=1){
                    q.push(m[node]);
                }
            }
            dis++;
        }
        return ans;
    }
};