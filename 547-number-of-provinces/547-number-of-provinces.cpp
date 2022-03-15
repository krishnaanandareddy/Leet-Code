class Solution {
    // here pass by reference for graph is important
    void dfs(vector<int> g[], vector<bool>& vis, int node){
        if(vis[node]==1)return;
        vis[node]=1;
        for(auto i:g[node]){
            dfs(g,vis,i);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& g1) {
        int n = g1.size();
        vector<int> g[n];
        for(int i = 0;i<n;i++){
            for(int j=0;j<n;j++){
                if(g1[i][j]==1 && i!=j){
                    g[i].push_back(j);
                }
            }
        }
        int ans = 0;
        vector<bool> vis(n,0);
        for(int i =0;i<n;i++){
            if(vis[i]==0){
                dfs(g,vis,i);
                ans++;
            }
        }
        return ans;
    }
};