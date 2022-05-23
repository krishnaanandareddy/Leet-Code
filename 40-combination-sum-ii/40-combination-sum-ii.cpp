class Solution {
    void add(int ci, int t, int n, vector<int>& curr, vector<int>& v, vector<vector<int>>& ans){
        if(t==0){
            ans.push_back(curr);
            return;
        }
        for(int i = ci;i<n;i++){
            if(i>ci && v[i]==v[i-1])continue;
            if(v[i]>t)break;
            curr.push_back(v[i]);
            add(i+1,t-v[i],n,curr,v,ans);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& v, int t) {
        sort(v.begin(),v.end());
        vector<vector<int>> ans;
        vector<int> curr;
        int n = v.size();
        add(0,t,n,curr,v,ans);
        return ans;
    }
};