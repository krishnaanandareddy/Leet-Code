class Solution {
public:
    int rob(vector<int>& v) {
        int n = v.size();
        vector<int> dp(n,0);
        for(int i=0;i<n;i++){
            if(i==0){
                dp[i]=v[i];
                continue;
            }
            int np = dp[i-1];
            int p = v[i];
            if(i>1)p+=dp[i-2];
            dp[i]=max(p,np);
        }
        return dp[n-1];
    }
};