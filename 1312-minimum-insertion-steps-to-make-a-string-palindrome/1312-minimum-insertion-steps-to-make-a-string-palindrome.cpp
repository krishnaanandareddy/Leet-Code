class Solution {
    int ans(string& s, string& s1, int i, int i1, vector<vector<int>>& dp){
        if(i<0 || i1<0)return 0;
        if(dp[i][i1]!=-1)return dp[i][i1];
        if(s[i]==s1[i1]){
            dp[i][i1] = 1+ans(s,s1,i-1,i1-1,dp);
        }
        else{
            dp[i][i1] = max(ans(s,s1,i,i1-1,dp),ans(s,s1,i-1,i1,dp));
        }
        return dp[i][i1];
    }
public:
    int minInsertions(string s) {
        string s1 = s;
        reverse(s.begin(),s.end());
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int temp = ans(s,s1,n-1,n-1,dp);
        // cout<<temp;
        return n-temp;
    }
};