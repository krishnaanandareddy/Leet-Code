class Solution {
public:
    vector<int> twoSum(vector<int>& v, int t) {
        int n = v.size();
        int i1 = 0;
        int i2 = n-1;
        int sum;
        while(v[i1]+v[i2]!=t && i1<i2){
            sum = v[i1]+v[i2];
            if(sum>t){
                i2--;
            }
            else{
                i1++;
            }
        }
        vector<int> ans;
        ans.push_back(i1+1);
        ans.push_back(i2+1);
        return ans;
    }
};