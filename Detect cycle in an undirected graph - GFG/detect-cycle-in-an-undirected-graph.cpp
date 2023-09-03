//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    int cycle = 0;
    void bfs(int i, int par, int n, vector<int> adj[], int vis[]){
        if(vis[i]==1 || cycle == 1){
            cycle = 1;
            return;
        }
        vis[i] = 1;
        for(int c: adj[i]){
            if(c==par)continue;
            bfs(c,i, n, adj, vis);
        }
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int n, vector<int> adj[]) {
        // Code here
        int vis[n]= {0};
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                bfs(i,-1, n, adj, vis);
                if(cycle == 1)return 1;
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends