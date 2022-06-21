class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid[0].size();
        int ans = 0;
        for(auto v:grid){
            for(auto i:v){
                if(i<0)ans++;
            }
        }
        return ans;
    }
};