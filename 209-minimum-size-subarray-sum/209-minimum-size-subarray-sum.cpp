class Solution {
public:
    int minSubArrayLen(int t, vector<int>&v ) {
        int n = v.size();
        int s = 0;
        int curr = 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            curr+=v[i];
            while(1){
                if(curr-v[s]>=t){
                    curr-=v[s];
                    s++;
                }
                else{
                    break;
                }
            }
            if(curr>=t)ans = (ans==0)?i+1-s:min(ans,i+1-s);
        }
        return ans;
    }
};