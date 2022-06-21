class Solution {
public:
    int pivotIndex(vector<int>& v) {
        int n = v.size();
        vector<int> ls(n);
        vector<int> rs(n);
        for(int i=1;i<n;i++){
            ls[i]=ls[i-1]+v[i-1];
        }
        for(int i=n-2;i>=0;i--){
            rs[i]=rs[i+1]+v[i+1];
        }
        for(int i=0;i<n;i++){
            if(ls[i]==rs[i])return i;
        }
        return -1;
    }
};