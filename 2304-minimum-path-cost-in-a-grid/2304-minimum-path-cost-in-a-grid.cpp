class Solution {
public:
    int minPathCost(vector<vector<int>>& v, vector<vector<int>>& cost) {
        int m=v.size();
        int n = v[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        int ans = INT_MAX;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                dp[i][j]=v[i][j];
                if(i>0){
                    int temp = 0;
                    int t = INT_MAX;
                    for(int k=0;k<n;k++){
                        int val = v[i-1][k];
                        temp=dp[i-1][k];
                        temp+=cost[val][j];
                        t=min(t,temp);
                        // cout<<t<<" ";
                    }
                    dp[i][j]+=t;
                    // cout<<dp[i][j]<<" ";
                    if(i==m-1){
                        ans=min(ans,dp[i][j]);
                    }
                }
            }
        }
        return ans;
    }
};