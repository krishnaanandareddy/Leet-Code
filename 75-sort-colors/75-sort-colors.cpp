class Solution {
public:
    void sortColors(vector<int>& v) {
        int c0=0;
        int c1=0;
        int c2=0;
        for(int i=0;i<v.size();i++){
            if(v[i]==0)c0++;
            if(v[i]==1)c1++;
            if(v[i]==2)c2++;
        }
        for(int i=0;i<v.size();i++){
            if(c0>0){
                v[i]=0;
                c0--;
            }
            else if(c1>0){
                v[i]=1;
                c1--;
            }
            else{
                v[i]=2;
            }
        }
    }
};