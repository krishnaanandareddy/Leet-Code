class Solution {
    bool check(int i, int j, int m, int n){
        if(i<0 || j<0 || i>=m || j>=n){
            return 0;
        }
        return 1;
    }
    void bfs(vector<vector<int>>& v, vector<vector<int>>& dp, vector<vector<int>>& vis,  int i, int j){
        if(vis[i][j]==1)return;
        int m = v.size(), n = v[0].size();
        vis[i][j]=1;
        dp[i][j]=1;
        int op1 = 0, op2 = 0, op3 = 0, op4 = 0;
        if(check(i+1,j,m,n)){
            if(v[i+1][j]>v[i][j]){
                if(vis[i+1][j]==0)bfs(v,dp,vis,i+1,j);
                op1 = dp[i+1][j];
            }
        }
        if(check(i,j+1,m,n)){
            if(v[i][j+1]>v[i][j]){
                if(vis[i][j+1]==0)bfs(v,dp,vis,i,j+1);
                op2 = dp[i][j+1];
            }
        }
        if(check(i-1,j,m,n)){
            if(v[i-1][j]>v[i][j]){
                if(vis[i-1][j]==0)bfs(v,dp,vis,i-1,j);
                op3 = dp[i-1][j];
            }
        }
        if(check(i,j-1,m,n)){
            if(v[i][j-1]>v[i][j]){
                if(vis[i][j-1]==0)bfs(v,dp,vis,i,j-1);
                op4 = dp[i][j-1];
            }
        }
        int t = max(op1,op2);
        t = max(op3,t);
        t= max(op4,t);
        dp[i][j] = t+1;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& v) {
        int m = v.size(), n = v[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        vector<vector<int>> vis(m,vector<int>(n,0));
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==0){
                    bfs(v,dp,vis,i,j);
                }
                ans = max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};