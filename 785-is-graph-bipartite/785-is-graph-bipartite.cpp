class Solution {
public:
    bool isBipartite(vector<vector<int>>& g) {
        int n = g.size();
        vector<int> vis(n,-1);
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                queue<int> q;
                q.push(i);
                vis[i] = 0;
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    for(auto x:g[node]){
                        int child = x;
                        if(vis[child]==-1){
                            vis[child] = 1-vis[node];
                            q.push(child);
                        }
                        else if(vis[child]+vis[node]!=1){
                            // cout<<child<<" "<<node;
                            return 0;
                        }
                    }
                }
            }
        }
        return 1;
        
    }
};