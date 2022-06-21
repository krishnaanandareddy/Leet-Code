class Solution {
public:
    int specialArray(vector<int>& v) {
        int n = v.size();
        int s=0;
        int e=n;
        sort(v.begin(),v.end());
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            if(m[v[i]])continue;
            m[v[i]]=n-i;
            while(v[i]--){
                if(m[v[i]])break;
                m[v[i]]=n-i;
            }
        }
        for(int i=0;i<=n;i++){
            if(m[i]==i)return i;
        }
        return -1;
    }
};