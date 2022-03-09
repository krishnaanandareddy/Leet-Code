class Solution {
    void visit(int i, int j, vector<vector<char>>& grid){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j]!='1'){
            return;
        }
        grid[i][j]='2';
        visit(i+1,j,grid);
        visit(i,j+1,grid);
        visit(i-1,j,grid);
        visit(i,j-1,grid);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        if(rows == 0)return 0;
        int ans = 0;
        for(int i=0;i<rows;i++){
            for(int j = 0; j<cols; j++){
                if(grid[i][j]=='1'){
                    ans++;
                    visit(i,j,grid);
                }
            }
        }
        return ans;
    }
};