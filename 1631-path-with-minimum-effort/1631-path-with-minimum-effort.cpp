class Solution {
    bool allow(int m, int n, int x, int y){
        if(x>=0 && y>=0 && x<m && y<n)return 1;
        return 0;
    }
public:
    int minimumEffortPath(vector<vector<int>>& v) {
        int m = v.size();
        int n = v[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>> >,greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> dp(m,vector<int>(n,INT_MAX));
        pq.push({0,{m-1,n-1}});
        dp[m-1][n-1]=0;
        vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        while(!pq.empty()){
            int dd = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();
            for(auto d:dir){
                int x = i+d.first;
                int y = j+d.second;
                if(allow(m,n,x,y)){
                    int dc = dp[x][y];
                    int temp = abs(v[i][j]-v[x][y]);
                    temp=max(temp,dd);
                    if(temp < dc){
                        dp[x][y] = temp;
                        pq.push({temp,{x,y}});
                    }
                }
            }
        }
        return dp[0][0];
    }
};