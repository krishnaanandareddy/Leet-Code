class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int,double>> g[n];
        for(int i=0;i<edges.size();i++){
            g[edges[i][0]].push_back({edges[i][1],succProb[i]});
            g[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        priority_queue<pair<double,int>,vector<pair<double,int> >> pq;
        vector<double>prob(n,0);
        prob[start] = 1;
        pq.push({1,start});
        while(!pq.empty()){
            int node = pq.top().second;
            double p = pq.top().first;
            pq.pop();
            for(auto i:g[node]){
                int child = i.first;
                double pc = i.second;
                // cout<<pc;
                if(pc*p>prob[child]){
                    prob[child]=pc*p;
                    pq.push({prob[child],child});
                }
                // cout<<child<<" "<<pc<<" "<<p<<" ";
            }
        }
        return prob[end];
    }
};