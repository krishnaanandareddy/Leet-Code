class Solution {
    bool valid(int m, int n, int x, int y){
        if(x>=0 && y>=0 && x<m && y<n)return 1;
        return 0;
    }
public:
    int orangesRotting(vector<vector<int>>& v) {
        int ans = 0;
        queue<pair<int,int>> q;
        int m = v.size();
        int n = v[0].size();
        bool f = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(v[i][j]==2){
                    q.push({i,j});
                }
                if(v[i][j]==1)f=1;
            }
        }
        if(q.size()==0){
            if(f==0)return 0;
            else return -1;
        }
        vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        while(q.size()){
            int s = q.size();
            ans++;
            for(int z=0;z<s;z++){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                for(auto d:dir){
                    int x = i+d.first;
                    int y = j+d.second;
                    if(valid(m,n,x,y)){
                        if(v[x][y]==1){
                            v[x][y]=2;
                            q.push({x,y});
                        }
                    }
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(v[i][j]==1){
                    return -1;
                }
            }
        }        
        return ans-1;
    }
};