class Solution {
public:
    bool isPowerOfTwo(int n) {
        long long int x = n;
        if(x==0)return 0;
        return !(x&(x-1));
    }
};