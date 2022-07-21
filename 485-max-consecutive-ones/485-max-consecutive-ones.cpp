class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& v) {
        int prev = 0;
        int curr = 0;
        int ans = 0;
        for(auto i:v){
            if(i==1){
                curr++;
                ans = max(ans, curr);
            }
            else{
                curr=0;
            }
        }
        return ans;
    }
};