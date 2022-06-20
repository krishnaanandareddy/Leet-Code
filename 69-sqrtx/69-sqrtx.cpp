class Solution {
public:
    int mySqrt(int x) {
        if(x==0)return 0;
        long long sum = 0;
        int i;
        for(i=1;i<=x;i=i+2){
            sum+=i;
            if(sum==x)return (i+1)/2;
            else if(sum>x)return (i-1)/2;
        }
        return (i-1)/2;
    }
};