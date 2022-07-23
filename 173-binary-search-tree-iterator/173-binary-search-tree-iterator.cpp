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
class BSTIterator {
    vector<int> in;
    int i = 0;
    int n = 0;
    void fill(TreeNode* root){
        if(root==NULL)return;
        fill(root->left);
        in.push_back(root->val);
        fill(root->right);
    }
public:
    BSTIterator(TreeNode* root) {
        fill(root);
        n=in.size();
    }
    
    int next() {
        int ind = i;
        i++;
        return in[ind];
    }
    
    bool hasNext() {
        if(i<n)return 1;
        return 0;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */