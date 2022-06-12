class Solution {
public:
    vector<int> successfulPairs(vector<int>& s, vector<int>& p, long long t) {
        int n = s.size();
        vector<int> ans(n,0);
        int n2 = p.size();
        sort(p.begin(),p.end());
        vector<pair<int,int>> m;
        for(int i=0;i<n;i++){
            m.push_back({s[i],i});
        }
        sort(m.begin(),m.end());
        int curr=n2-1;
        int c = 0;
        for(auto i:m){
            long long temp = i.first;
            long long index = i.second;
            long long mul;
            for(;curr>=0;curr--){
                mul = p[curr]*temp;
                if(mul<t){
                    break;
                }
                c++;
            }
            ans[index]=c;
        }
        return ans;
    }
};