class Solution {
public:
    int pivotIndex(vector<int>& v) {
        int n = v.size();
        long long s = 0;
        for(int i=0;i<n;i++){
            long long temp = v[i];
            s+=temp;
        }
        long long curr = 0;
        for(int i=0;i<n;i++){
            if(curr*2 == s-v[i])return i;
            long long temp = v[i];
            curr+=temp;
        }        
        return -1;
    }
};