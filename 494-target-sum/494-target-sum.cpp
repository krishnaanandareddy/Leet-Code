class Solution {
    int fill(vector<int>& v, vector<vector<int>>& dp, int i, int t, int sum){
        int n = v.size();
        if(i==n){
            if(t==0)return 1;
            else return 0;
        }
        int tt = t+sum;
        // cout<<tt<<" "<<t<<endl;
        if(dp[i][tt]!=-1)return dp[i][tt];
        int add = fill(v,dp,i+1,t-v[i],sum);
        int sub = fill(v,dp,i+1,t+v[i],sum);
        return dp[i][tt] = add+sub;
    }
public:
    int findTargetSumWays(vector<int>& v, int t) {
        int n = v.size();
        int sum = 0;
        for(auto i:v)sum+=abs(i);
        sum+=abs(t);
        // cout<<sum<<endl;
        vector<vector<int>> dp(n,vector<int>(sum+sum+t+1,-1));
        return fill(v,dp,0,t,sum);
    }
};