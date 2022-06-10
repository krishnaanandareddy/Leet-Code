class Solution {
    int ans(string& s1, string& s2, int i1, int i2, vector<vector<int>>& dp){
        if(i1<0)return i2+1;
        if(i2<0)return i1+1;
        if(dp[i1][i2]!=-1)return dp[i1][i2];
        if(s1[i1]==s2[i2]){
            dp[i1][i2] = ans(s1,s2,i1-1,i2-1,dp);
        }
        else{
            dp[i1][i2] = min(1+ans(s1,s2,i1,i2-1,dp),1+ans(s1,s2,i1-1,i2-1,dp));
            dp[i1][i2] = min(dp[i1][i2],1+ans(s1,s2,i1-1,i2,dp));
        }
        return dp[i1][i2];
    }
public:
    int minDistance(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        vector<vector<int>> dp(n1,vector<int>(n2,-1));
        return ans(s1,s2,n1-1,n2-1,dp);
    }
};