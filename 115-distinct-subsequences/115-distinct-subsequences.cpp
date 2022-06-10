class Solution {
public:
    int numDistinct(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        int m = 1e9+7;
        vector<vector<long long>> dp(n1+1,vector<long long>(n2+1,0));
        for(int i1=0;i1<=n1;i1++){
            for(int i2=0;i2<=n2;i2++){
                if(i2==0){
                    dp[i1][i2]=1;
                    continue;
                }
                if(i1==0)continue;
                if(s1[i1-1]==s2[i2-1]){
                    dp[i1][i2] = (dp[i1-1][i2-1]%m + dp[i1-1][i2]%m)%m;
                }
                else{
                    dp[i1][i2] = dp[i1-1][i2]%m;
                }
            }
        }
        return dp[n1][n2];
    }
};