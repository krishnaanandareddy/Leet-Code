class Solution {
public:
    int minimumTotal(vector<vector<int>>& v) {
        int n = v.size();
        long long dp[n][n];
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=i;j++){
                dp[i][j]=v[i][j];
                if(i==n-1)continue;
                int op1 = dp[i+1][j];
                int op2 = dp[i+1][j+1];
                dp[i][j]+=min(op1,op2);
            }
        }
        return dp[0][0];
    }
};