class Solution {
    void dfs(vector<vector<int>>& g,vector<bool> &visited,int node){
        if(visited[node]==1){
            return;
        }
        visited[node]=1;
        for(int child: g[node]){
            dfs(g,visited,child);
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& g) {
        int n = g.size();
        vector<bool> visited(n,0);
        dfs(g,visited,0);
        bool ans = true;
        for(bool b:visited){
            if(b==0)ans = false;
        }
        return ans;
    }
};