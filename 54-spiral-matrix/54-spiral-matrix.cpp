class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();
        vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
        int curr = 0;
        int i=0,j=0;
        vector<int> ans;
        while(v[i][j]!=INT_MAX){
            ans.push_back(v[i][j]);
            v[i][j]=INT_MAX;
            int t = 4;
            while(t--){
                curr = curr%4;
                int x = dir[curr][0]+i;
                int y = dir[curr][1]+j;
                if(x>=0 && x<n && y>=0 && y<m && v[x][y]!=INT_MAX){
                    i=x;
                    j=y;
                    break;
                }
                curr++;
            }
        }
        return ans;
    }
};