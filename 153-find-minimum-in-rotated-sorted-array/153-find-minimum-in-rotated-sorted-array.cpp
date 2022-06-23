class Solution {
public:
    int findMin(vector<int>& v) {
        int n = v.size();
        int ans = 0;
        int s = 0, e = n-2;
        while(s<=e){
            int m = s+(e-s)/2;
            if(v[m]>v[m+1])return v[m+1];
            else if(v[m]>=v[n-1])s=m+1;
            else e=m-1;
        }
        return v[0];
    }
};