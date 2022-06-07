class Solution {
    bool find(vector<vector<int>>& dp, vector<int>& v, int i, int t){
        if(i==0){
            if(v[i]==t)return 1;
            return 0;
        }
        if(t==0)return 1;
        if(dp[i][t]!=-1){
            return dp[i][t];
        }
        bool pick = 0;
        if(v[i]<=t)
            pick = find(dp,v,i-1,t-v[i]);
        bool np = find(dp,v,i-1,t);
        dp[i][t]=pick|np;
        return pick|np;
    }
public:
    bool canPartition(vector<int>& v) {
        int n = v.size();
        int sum = 0;
        for(int i:v)sum+=i;
        if(sum%2!=0)return 0;
        int t = sum/2;
        vector<vector<int>> dp(n,vector<int> (t+1,-1));
        return find(dp,v,n-1,t);
    }
};