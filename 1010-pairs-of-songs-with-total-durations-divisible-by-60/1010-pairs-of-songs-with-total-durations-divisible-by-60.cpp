class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& t) {
        vector<int> ew(61,0);
        for(int i=0;i<t.size();i++){
            t[i]%=60;
            ew[t[i]]++;
        }
        long long int ans=0;
        for(int i=1;i<30;i++){
            if(ew[i]>0 && ew[60-i]>0){
                ans+=ew[i]*ew[60-i];
            }
        }
        if(ew[30]>0){
            ans+=ew[30]*(ew[30]-1)/2;
        }
        if(ew[0]>0){
            ans+=ew[0]*(ew[0]-1)/2;
        }
        return ans;
        
    }
};