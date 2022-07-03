class Solution {
    bool same(int i, int j){
        if(i>=0 && j>=0)return 1;
        if(i<=0 && j<=0)return 1;
        return 0;
    }
public:
    int wiggleMaxLength(vector<int>& v) {
        int n = v.size();
        if(n<2)return n;
        if(n<3){
            if(v[0]==v[1])return 1;
            return n;
        }
        int prev = v[1]-v[0];
        int ans = 0;
        for(int i=2;i<n;i++){
            int curr = v[i] - v[i-1];
            if(prev==0){
                prev = curr;
                ans++;
                continue;
            }
            if(same(prev,curr)){
                ans++;
            }
            else{
                prev = curr;
            }
        }
        if(prev==0)ans++;
        return n-ans;
    }
};