class Solution {
public:
    int bitwiseComplement(int n) {
        long long int sum;
        if(n==0){
            return 1;
        }
        for(int i=0;i<32;i++){
            sum = (1LL<<i)-1;
            if(sum>=n){
                break;
            }
        }
        long long int ans = sum - n;
        return ans;
    }
};