class Solution {
public:
    int firstMissingPositive(vector<int>& v) {
        sort(v.begin(),v.end());
        int n = v.size();
        int diff;
        if(v[0]>1)return 1;
        if(v[n-1]<0)return 1;
        for(int i = 0; i<n-1; i++){
            diff = v[i+1]-v[i];
            if(diff>1){
                if(v[i+1]>0){
                    if(v[i]>0){
                        return v[i]+1;
                    }
                    else{
                        if(v[i+1]>1){
                            return 1;
                        }
                    }
                }
            }
        }
        return v[n-1]+1;
    }
};