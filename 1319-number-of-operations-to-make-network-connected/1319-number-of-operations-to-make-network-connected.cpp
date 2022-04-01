class Solution {
    void dfs(vector<int> g[],int node, vector<int>&vis){
        if(vis[node]==1)return;
        vis[node]=1;
        for(auto i:g[node]){
            dfs(g,i,vis);
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& c) {
        int ne = c.size();  //no.of edges //A graph of n nodes should have atleast n-1 edges to be fully connected
        if(ne<n-1){
            return -1;
        }
        vector<int>vis(n,0);
        vector<int> g[n];
        for(int i=0;i<ne;i++){
            g[c[i][0]].push_back(c[i][1]);
            g[c[i][1]].push_back(c[i][0]);
        }
        int nconn = 0;  //no.of connected components
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                dfs(g,i,vis);
                nconn++;
            }
        }
        //if we have k connected components we need k-1 cables to connect them just think them like no.of edges to connect k nodes to form a connected graph
        return nconn-1;
    }
};