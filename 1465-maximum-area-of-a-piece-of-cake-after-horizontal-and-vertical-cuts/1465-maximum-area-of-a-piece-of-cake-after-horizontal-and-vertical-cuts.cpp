class Solution {
public:
    int maxArea(int h, int w, vector<int>& v1, vector<int>& v2) {
        v1.push_back(0);
        v2.push_back(0);
        v2.push_back(w);
        v1.push_back(h); 
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        int r = 0;
        for(int i=1;i<v1.size();i++){
            int d = v1[i]-v1[i-1];
            r = max(r,d);
        }
        int c = 0;
        for(int j=1;j<v2.size();j++){
            int d = v2[j]-v2[j-1];
            c = max(c,d);
        }
        long long temp1 = r;
        long long temp2 = c;
        int m = 1e9+7;
        long long ans = ((temp1%m)*(temp2%m))%m;
        return ans;
    }
};