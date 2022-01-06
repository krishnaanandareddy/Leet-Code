class Solution {
public:
    bool containsDuplicate(vector<int>& v) {
        int n = v.size();
        sort(v.begin(),v.end());
        for(int i=0;i<n-1;i++){
            if(v[i]==v[i+1]){
                return true;
            }
        }
        return false;
    }
};