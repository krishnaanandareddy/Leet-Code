class Solution {
public:
    bool wordBreak(string s, vector<string>& d) {
        int n = s.size();
        unordered_map<string,int> m;
        for(auto i:d){
            m[i]=1;
        }
        vector<bool> dp(n+1,0);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=i-1;j>=0;j--){
                if(dp[j]){
                    string s1 = s.substr(j,i-j);
                    if(m[s1]){
                        dp[i]=1;
                        continue;
                    }
                }
            }
        }
        return dp[n];
    }
};