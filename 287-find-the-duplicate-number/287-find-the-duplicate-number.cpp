class Solution {
public:
    int findDuplicate(vector<int>& v) {
        int n = v.size();
        sort(v.begin(),v.end());
        int temp = v[0];
        int ans=-1;
        for(int i=1;i<n;i++){
            if(temp==v[i]){
                ans = temp;
                break;
            }
            else temp = v[i];
        }
        return ans;
    }
};