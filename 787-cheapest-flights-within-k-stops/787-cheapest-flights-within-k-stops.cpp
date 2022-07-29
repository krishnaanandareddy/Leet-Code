class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> g[n];
        for(auto f:flights){
            g[f[0]].push_back({f[1],f[2]});
        }
        queue<pair<int,int>> q;
        q.push({src,0});
        vector<int> distto(n,INT_MAX);
        distto[src]=0;
        int ans = INT_MAX;
        int stops = 0;
        while(!q.empty() && stops<=k){
            int s=q.size();
            for(int i=0;i<s;i++){
                int node = q.front().first;
                int dist = q.front().second;
                q.pop();
                for(auto child:g[node]){
                    if(dist+child.second>ans)continue;
                    if(distto[child.first]<dist+child.second)continue;
                    q.push({child.first,dist+child.second});
                    distto[child.first] = dist+child.second;
                    if(child.first==dst){
                        ans=min(ans,dist+child.second);
                    }
                }
            }
            stops++;
        }
        if(ans==INT_MAX)return -1;
        return ans;
    }
};