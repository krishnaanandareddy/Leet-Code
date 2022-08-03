class Solution {
public:
    int subarraySum(vector<int>& v, int k) {
        int n = v.size();
        unordered_map<int,int> m;
        int curr = 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            curr+=v[i];
            int temp = curr-k;
//             edge case
            if(curr==k)ans++;
            if(m[temp]!=0)ans+=m[temp];
            m[curr]++;
        }
        return ans;
    }
};