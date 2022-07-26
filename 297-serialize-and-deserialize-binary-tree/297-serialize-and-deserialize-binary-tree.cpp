/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string l;
        if(root==NULL)return l;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node!=NULL){
                string temp = to_string(node->val);
                l+=temp;
                l+=",";
                q.push(node->left);
                q.push(node->right);
            }
            else{
                l+="#,";
            }
        }
        if(l.size()>0)l.pop_back();
        // cout<<l;
        return l;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string l) {
        vector<int> values;
        // cout<<l;
        if(l.size()==0)return NULL;
        int temp = 0;
        bool n=0;
        for(int i=0;i<l.size();i++){
            if(l[i]==','){
                if(n==1){
                    temp*=-1;
                    n=0;
                }
                values.push_back(temp);
                // cout<<to_string(-1);
                temp=0;
            }
            else if(l[i]=='-'){
                n=1;
                // i++;
            }
            else if(l[i]=='#'){
                i++;
                values.push_back(1e5);
            }
            else{
                temp=temp*10;
                temp+=l[i]-'0';
            }
        }
        int i = 1;
        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(values[0]);
        TreeNode* tempp = root;
        q.push(tempp);
        bool f=0;
        for(i=1;i<values.size();i++){
            TreeNode* par = q.front();
            tempp = new TreeNode(values[i]);
            if(values[i]==1e5){
                tempp = NULL;
            }
            else{
                q.push(tempp);
            }
            if(f==0){
                par->left = tempp;
            }
            else {
                par->right = tempp;
                q.pop();
            }
            f=1-f;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));