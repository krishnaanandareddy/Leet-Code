class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int s = strs.size();
        vector<vector<vector<int>>>dp(s,vector<vector<int>>(m+1,vector<int>(n+1,0)));
        vector<pair<int,int>> sizes;
        for(auto v:strs){
            int z = 0;
            for(auto i:v)if(i=='0')z++;
            int temp = v.size();
            sizes.push_back({z,temp-z});
        }
        for(int i=0;i<s;i++){
            int o = sizes[i].second;
            int z = sizes[i].first;
            for(int j=0;j<=m;j++){
                for(int k=0;k<=n;k++){
                    int p = 0;
                    int np = 0;;
                    if(o<=k && z<=j){
                        p = 1;
                        if(i>0)p+=dp[i-1][j-z][k-o];
                    }
                    if(i>0)np = dp[i-1][j][k];
                    dp[i][j][k] = max(p,np);
                }
            }
        }
        return dp[s-1][m][n];
    }
};