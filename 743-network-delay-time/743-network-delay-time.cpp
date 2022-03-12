class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> g[n+1];
        for(auto i:times){
            g[i[0]].push_back({i[1],i[2]});
        }
        set<pair<int,int>> s;
        s.insert({0,k});
        vector<int> dist(n+1,1e5+10);
        dist[k]=0;
        vector<int> vis(n+1,0);
        while(s.size()>0){
            auto nodemin = *s.begin();
            int node_dist = nodemin.first;
            int node = nodemin.second;
            s.erase(s.begin());
            // if(vis[node]==1)continue;
            // vis[node]=1;
            for(auto i: g[node]){
                int child = i.first;
                int wt = i.second;
                if(dist[node]+wt<dist[child]){
                    s.insert({dist[node]+wt,child});
                    dist[child] = dist[node]+wt;
                }
            }
        }
        int ans = 0;
        for(int i = 1;i<=n;i++){
            if(dist[i]==1e5+10)return -1;
            ans = max(ans,dist[i]);
        }
        return ans;
    }
};