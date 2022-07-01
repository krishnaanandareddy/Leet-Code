class Solution {
    bool allow(int x,int y,int m, int n){
        if(x>=0 && y>=0 && x<m && y<n)return 1;
        return 0;
    }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& v) {
        int m = v.size();
        int n = v[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> ans(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(v[i][j]==0){
                    q.push({i,j});
                    ans[i][j]=0;
                }
            }
        }
        vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for(auto d:dir){
                int x = i+d.first;
                int y = j+d.second;
                if(allow(x,y,m,n) && ans[x][y]==-1){
                    ans[x][y] = 1+ans[i][j];
                    q.push({x,y});
                }
            }
        }
        return ans;
    }
};