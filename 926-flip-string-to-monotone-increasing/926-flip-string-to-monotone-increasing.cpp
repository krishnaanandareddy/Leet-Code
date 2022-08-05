class Solution {
public:
    int minFlipsMonoIncr(string v) {
        int n = v.size();
        vector<int> f0(n+1,0),f1(n+1,0);
        for(int i=1;i<=n;i++){
            f0[i]+=f0[i-1];
            if(v[i-1]=='1')f0[i]++;
        }
        int ans = INT_MAX;
        ans = min(f0[n]+f1[n],ans);
        for(int i=n-1;i>=0;i--){
            f1[i]+=f1[i+1];
            if(v[i]=='0')f1[i]++;
            ans = min(ans,f1[i]+f0[i]);
        }
        return ans;
    }
};