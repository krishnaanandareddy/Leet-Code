class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        for(int i1=1;i1<=n1;i1++){
            for(int i2=1;i2<=n2;i2++){
                if(s1[i1-1]==s2[i2-1])dp[i1][i2]=1+dp[i1-1][i2-1];
                else dp[i1][i2]=max(dp[i1][i2-1],dp[i1-1][i2]);
            }
        }
        int n = dp[n1][n2];
        string lcs(n,'$');
        int i1 = n1;
        int i2 = n2;
        int i = n-1;
        while(i1>0 && i2>0){
            if(s1[i1-1]==s2[i2-1]){
                lcs[i] = s1[i1-1];
                i1--;
                i2--;
                i--;
            }
            else if(dp[i1][i2]==dp[i1][i2-1]){
                i2--;
            }
            else{
                i1--;
            }
        }
        i1=0;
        i2=0;
        string ans="";
        for(i=0;i<n;i++){
            while(s1[i1]!=lcs[i]){
                ans+=s1[i1];
                i1++;
            }
            while(s2[i2]!=lcs[i]){
                ans+=s2[i2];
                i2++;
            }
            ans+=lcs[i];
            i1++;
            i2++;
        }
        if(i1<n1){
            for(;i1<n1;i1++){
                ans+=s1[i1];
            }
        }
        if(i2<n2){
            for(;i2<n2;i2++)ans+=s2[i2];
        }
        return ans;
    }
};