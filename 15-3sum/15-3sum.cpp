class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& v) {
        int n  = v.size();
        vector<vector<int>> ans;
        unordered_map<int,int> m;
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++){
            if(m[v[i]])continue;
            m[v[i]]=1;
            int t = -v[i];
            int s = i+1;
            int e = n-1;
            while(s<e && s<n){
                int sum = v[s] + v[e];
                if(sum>t)e--;
                else if(sum<t)s++;
                else{
                    ans.push_back({v[i],v[s],v[e]});
                    while(s<e && v[s+1]==v[s]){
                        s++;
                    }
                    while(s<e && v[e-1]==v[e]){
                        e--;
                    }
                    s++;
                    e--;
                }
            }
        }
        return ans;
    }
};