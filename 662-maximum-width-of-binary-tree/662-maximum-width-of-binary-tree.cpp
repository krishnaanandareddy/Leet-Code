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
    int widthOfBinaryTree(TreeNode* t) {
        queue<pair<TreeNode*,long long>> q;
        q.push({t,0});
        int ans = INT_MIN;
        while(!q.empty()){
            long long n = q.size();
            long long mn = q.front().second;
            long long f,l;
            for(long long i=0;i<n;i++){
                if(i==0)f=q.front().second;
                if(i==n-1)l=q.front().second;
                TreeNode* temp = q.front().first;
                long long j = q.front().second - mn;
                q.pop();
                if(temp->left!=NULL)
                    q.push({temp->left,2*(j)+1});
                if(temp->right!=NULL)
                    q.push({temp->right,2*(j)+2});
            }
            if(l-f+1>ans)ans=l-f+1;
        }
        return ans;
    }
};