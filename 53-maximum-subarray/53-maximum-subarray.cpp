class Solution {
public:
    int maxSubArray(vector<int>& v) {
        int ans = v[0];
        int sum = 0;
        for(int i= 0;i<v.size();i++){
            sum+=v[i];
            ans = max(sum,ans);
            if(sum<0){
                sum=0;
            }
        }
        return ans;
    }
};