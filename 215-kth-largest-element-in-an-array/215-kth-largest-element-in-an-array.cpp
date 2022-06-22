class Solution {
public:
    int findKthLargest(vector<int>& v, int k) {
        int n = v.size();
        sort(v.begin(),v.end());
        return v[n-k];
    }
};