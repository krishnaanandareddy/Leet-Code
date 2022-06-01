class Solution {
public:
    int minPathSum(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();
        long long dp[n][m];
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i==n-1 && j==m-1){
                    dp[i][j] = v[i][j];
                    continue;
                }
                long long op1=v[i][j],op2=v[i][j];
                if(i!=n-1)op1+=dp[i+1][j];
                else op1 = INT_MAX;
                if(j!=m-1)op2+=dp[i][j+1];
                else op2 = INT_MAX;
                // cout<<i<<" "<<j<<" "<<op1<<" "<<op2<<endl;
                dp[i][j]=min(op1,op2);
            }
        }
        return dp[0][0];
    }
};