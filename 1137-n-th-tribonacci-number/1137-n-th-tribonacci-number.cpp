class Solution {
public:
    int tribonacci(int n) {
        vector<int> tib;
        tib.push_back(0);
        tib.push_back(1);
        tib.push_back(1);
        if(n>2){
            for(int i=3;i<=n;i++){
                tib.push_back(tib[i-1]+tib[i-2]+tib[i-3]);
            }
        }
        return tib[n];
    }
};