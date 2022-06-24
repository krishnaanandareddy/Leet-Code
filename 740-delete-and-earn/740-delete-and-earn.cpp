class Solution {
public:
    int deleteAndEarn(vector<int>& v) {
        map<int,int> m;
        for(int i:v)m[i]++;
        vector<int> dp(1e4+1,0);
        int ans = 0;
        for(int i=1;i<dp.size();i++){
            int freq = m[i];
            int pick = i*freq;
            if(i>1){
                pick+=dp[i-2];
            }
            int np = dp[i-1];
            dp[i] = max(pick,np);
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};