class Solution {
    int ans(string& s1, string& s2, int i1, int i2, vector<vector<int>>& dp){
        if(i1<0 || i2<0)return 0;
        if(dp[i1][i2]!=-1)return dp[i1][i2];
        if(s1[i1]==s2[i2]){
            dp[i1][i2] = 1+ans(s1,s2,i1-1,i2-1,dp);
        }
        else{
            dp[i1][i2] = max(ans(s1,s2,i1-1,i2,dp),ans(s1,s2,i1,i2-1,dp));
        }
        return dp[i1][i2];
    }
public:
    int longestPalindromeSubseq(string s1) {
        string s2 = s1;
        int n = s1.size();
        reverse(s1.begin(),s1.end());
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return ans(s1,s2,n-1,n-1,dp);
    }
};