class Solution {
public:
    vector<int> searchRange(vector<int>& v, int t) {
        int n = v.size();
        auto its  = lower_bound(v.begin(),v.end(),t);
        int s = its-v.begin();
        if(its==v.end())return {-1,-1};
        if(v[s]!=t)return {-1,-1};
        auto ite = upper_bound(v.begin(),v.end(),t);
        ite--;
        int e = ite-v.begin();
        return {s,e};
    }
};