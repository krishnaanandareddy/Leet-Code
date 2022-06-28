class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int> m;
        for(char c:s)m[c]++;
        unordered_map<int,int> f;
        for(auto i:m){
            f[i.second]++;
        }
        int ans = 0;
        for(auto i:f){
            int val = i.first;
            int freq = i.second;
            while(freq>1){
                int temp = val;
                while(f[temp]>=1){
                    if(temp==0)break;
                    temp--;
                    ans++;
                }
                f[temp] = 1;
                // cout<<temp;
                freq--;
            }
            f[val] =1;
        }
        return ans;
    }
};