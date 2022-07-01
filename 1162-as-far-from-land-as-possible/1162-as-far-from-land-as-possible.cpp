class Solution {
    bool  allow(int n, int x, int y){
        if(x>=0 && y>=0 && x<n && y<n)return 1;
        return 0;
    }
public:
    int maxDistance(vector<vector<int>>& g) {
        int n = g.size();
        bool one = 0;
        bool zero = 0;
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(g[i][j]==1){
                    q.push({i,j});
                    one = 1;
                }
                else zero = 1;                
            }
        }
        if(one==0 || zero == 0)return -1;
        vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        int ans = 0;
        while(!q.empty()){
            ans++;
            int s = q.size();
            for(int k=0;k<s;k++){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                for(auto d:dir){
                    int x = i+d.first;
                    int y = j+d.second;
                    if(allow(n,x,y) && g[x][y]==0){
                        g[x][y]=1;
                        q.push({x,y});
                        // cout<<x<<y<<" "<<ans<<" ";
                    }
                }
            }
        }
        return ans-1;
        // return q.size();
    }
};