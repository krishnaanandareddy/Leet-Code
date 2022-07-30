class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& v) {
        int n = v.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==0){
                    dp[i][j] = v[i][j];
                }
                else{
                    dp[i][j] = v[i][j];
                    int temp = INT_MAX;
                    for(int k=0;k<n;k++){
                        if(k==j)continue;
                        temp=min(temp,dp[i-1][k]);
                    }
                    dp[i][j]+=temp;
                }
                if(i==n-1){
                    ans = min(ans,dp[i][j]);
                }
            }
        }
        return ans;
    }
};