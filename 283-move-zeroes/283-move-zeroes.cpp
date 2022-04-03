class Solution {
public:
    void moveZeroes(vector<int>& v) {
        int n = v.size();
        int s=0,f=0;
        while(s<n){
            if(f<n)
                while(v[f]==0 && f<n){
                    f++;
                    if(f>=n)break;
                }
            if(f>=n){
                v[s]=0;
                s++;
            }
            else{
                v[s]=v[f];
                s++;
                f++;
            }
        }
        return;
    }
};