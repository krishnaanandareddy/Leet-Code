class Solution {
    int ans(vector<int>& v, int n, int i, bool b, vector<vector<int>>& dp){
        if(i>=n)return 0;
        if(dp[i][b]!=-1)return dp[i][b];
        int op1,op2;
        if(b==0){
            op1 = 0 + ans(v,n,i+1,0,dp);
            op2 = -v[i]+ans(v,n,i+1,1,dp);
        }
        else{
            op1 = 0 + ans(v,n,i+1,1,dp);
            op2 = v[i]+ans(v,n,i+1,0,dp);
        }
        dp[i][b] = max(op1,op2);
        return dp[i][b];
    }
public:
    int maxProfit(vector<int>& v) {
        int n = v.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return ans(v,n,0,0,dp);
    }
};