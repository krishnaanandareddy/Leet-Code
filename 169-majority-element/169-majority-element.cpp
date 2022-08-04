class Solution {
public:
    int majorityElement(vector<int>& v) {
        int n = v.size();
        unordered_map<int,int> m;
        for(int i=0;i<n;i++)m[v[i]]++;
        int ans = -1;
        int c = 0;
        for(auto i:m){
            if(c<i.second){
                c=i.second;
                ans = i.first;
            }
        }
        return ans;
    }
};