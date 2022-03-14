class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& g) {
        int n = g.size();
        vector<vector<int>> ans;
        queue<vector<int>> q;
        vector<int> temp;
        temp.push_back(0);
        q.push(temp);
        while(q.size()>0){
            vector<int> path = q.front();
            q.pop();
            int path_size = path.size();
            if(path[path_size-1]==n-1){
                ans.push_back(path);
                continue;
            }
            int node = path[path_size-1];
            path.push_back(node);
            for(auto child : g[node]){
                path[path_size] = child;
                q.push(path);
            }
        }
        return ans;
    }
};