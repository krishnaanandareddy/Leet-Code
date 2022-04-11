class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& v, int k) {
        int n = v.size();
        int m  = v[0].size();
        while(k--){
            for(int i = 0;i<n;i++){
                for(int j = 0;j<m;j++){
                    if(i==0 && j==0)continue;
                    swap(v[0][0],v[i][j]);
                }
            }
        }
        return v;
    }
};