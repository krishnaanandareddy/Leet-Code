class Solution {
public:
    int findLongestChain(vector<vector<int>>& v) {
        int n = v.size();
        sort(v.begin(),v.end());
        vector<int> dp(n,1);
        int ans = 1; 
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(v[i][0]>v[j][1]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};