class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();
        long long dp[n][m];
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(v[i][j]==1){
                    dp[i][j]=0;
                    continue;
                }
                if(i==n-1 && j==m-1){
                    dp[i][j]=1;
                }
                else{
                    dp[i][j]=0;
                    if(i!=n-1){
                        dp[i][j]+=dp[i+1][j];
                    }
                    if(j!=m-1){
                        dp[i][j]+=dp[i][j+1];
                    }
                }
            }
        }
        return dp[0][0];        
    }
};