class Solution {
public:
    int jump(vector<int>& v) {
        int n = v.size();
        int i = 0;
        int mx = 0;
        int ans = 0;
        while(i<n-1){
            ans++;
            int m = i;
            for(;i<=mx;i++){
                m = max(m, v[i]+i);
            }
            cout<<m;
            if(m>=n-1)return ans;
            mx = m;
        }
        return ans;
    }
};