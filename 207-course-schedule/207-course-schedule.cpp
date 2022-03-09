class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        vector<bool> visited(numCourses, false);
        vector<bool> dfsVisited(numCourses, false);
        
        for (auto pq: prerequisites)
            adj[pq[1]].push_back(pq[0]);
        
        auto res = true;
        
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                auto mres = checkForCycle(adj, visited, dfsVisited, i);
                res = res and mres;
            }
        }
        return res;
    }
        
    bool checkForCycle(vector<int> *adj, vector<bool> &visited, vector<bool> &dfsVisited, int v) {
        if (dfsVisited[v]) {
            return false;   
        }
        if (visited[v]) {
            return true;
        }
        visited[v] = true;
        dfsVisited[v] = true;
        
        auto res = true;
        
        for (auto c: adj[v])
            res = res and checkForCycle(adj, visited, dfsVisited, c);
        
        dfsVisited[v] = false;
        
        return res;
    }
};