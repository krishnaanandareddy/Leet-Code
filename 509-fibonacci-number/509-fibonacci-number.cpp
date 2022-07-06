class Solution {
public:
    int fib(int n) {
        if(n==0)return 0;
        if(n==1)return 1;
        vector<int>fib(n+1);
        int prev = 1;
        int prev2 = 0;
        for(int i=2;i<=n;i++){
            int curr = prev2+prev;
            fib[i]=curr;
            prev2 = prev;
            prev = curr;
        }
        return fib[n];
    }
};