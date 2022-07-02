class Solution {
    unordered_map<int,int> m,safe;
    bool dfs(vector<vector<int>>& g, vector<int>& vis, int node){
        if(safe[node]==1)return 1;
        vis[node]=1;
        bool val = 1;
        safe[node]=0;
        for(auto i:g[node]){
            if(vis[i]==0){
                val&=dfs(g,vis,i);
            }
            else{
                val&=safe[i];
            }
        }
        safe[node]=val;
        return val;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& g) {
        int n = g.size();
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                bool b = dfs(g,vis,i);
            }
        }
        vector<int> ans;
        for(auto i:safe){
            if(i.second==1){
                ans.push_back(i.first);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};