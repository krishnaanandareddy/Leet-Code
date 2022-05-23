class Solution {
    void add(int n, int ci, vector<int> &v, vector<vector<int>>& ans){
        if(ci==n){
            ans.push_back(v);
            return;
        }
        for(int i=ci;i<n;i++){
            swap(v[i],v[ci]);
            add(n,ci+1,v,ans);
            swap(v[i],v[ci]);
        }
    }    
public:
    vector<vector<int>> permute(vector<int>& v) {
        int n = v.size();
        vector<vector<int>> ans;
        add(n,0,v, ans);
        return ans;        
    }
};