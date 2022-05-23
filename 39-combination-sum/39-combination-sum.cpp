class Solution {
    void add(int ci, int t, vector<int>& v, vector<vector<int>>& ans, vector<int>& curr){
        int n = v.size();
        if(ci==n){
            if(t==0){
                ans.push_back(curr);
            }
            return;
        }
        if(t<0)return;
        curr.push_back(v[ci]);
        add(ci,t-v[ci],v,ans,curr);
        curr.pop_back();
        add(ci+1,t,v,ans,curr);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& v, int t) {
        vector<int> curr;
        vector<vector<int>> ans;
        add(0,t,v,ans,curr);
        return ans;
    }
};