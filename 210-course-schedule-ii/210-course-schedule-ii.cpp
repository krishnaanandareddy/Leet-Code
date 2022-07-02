class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<int> g[n];
        vector<int> in(n,0);
        for(auto v:p){
            g[v[1]].push_back(v[0]);
            in[v[0]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(in[i]==0)q.push(i);
        }
        vector<int> ans;
        int count = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;
            ans.push_back(node);
            for(auto child:g[node]){
                in[child]--;
                if(in[child]==0){
                    q.push(child);
                }
            }
        }
        if(count!=n)return {};
        return ans;
    }
};