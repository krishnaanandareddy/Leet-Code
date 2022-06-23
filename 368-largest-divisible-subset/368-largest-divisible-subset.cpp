class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& v) {
        int n = v.size();
        sort(v.begin(),v.end());
        vector<int> dp(n,1);
        int ind = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(v[i]%v[j]==0){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            if(dp[i]>dp[ind])ind=i;
        }
        vector<int> ans;
        int prev = v[ind];
        int val = dp[ind];
        cout<<ind;
        for(int i=ind;i>=0;i--){
            if(prev%v[i]==0 && val==dp[i]){
                ans.push_back(v[i]);
                val--;
                prev = v[i];
            }
        }
        return ans;
    }
};