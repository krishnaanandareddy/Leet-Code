// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
public:
void mindit(int a,int b,int n,int m,vector<vector<int>> &vi,vector<vector<int>> &grid,vector<int> &puma){
        if(a>=n || b>=m || grid[a][b]<0)return ;
        if(a==n-1 && b==m-1){
            puma.push_back(grid[a][b]);
            vi.push_back(puma);
            puma.pop_back();
            return;
        }
        
          puma.push_back(grid[a][b]);
          grid[a][b]=-1*grid[a][b];
          mindit(a+1,b,n,m,vi,grid,puma);
          mindit(a,b+1,n,m,vi,grid,puma);
          puma.pop_back();
          grid[a][b]=-1*grid[a][b];
        
     
    }
    vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &grid)
    {
        // code here
        vector<vector<int>> vi;
        vector<int> puma;
        mindit(0,0,n,m,vi,grid,puma);
        
        return vi;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution ob;
        auto ans = ob.findAllPossiblePaths(n, m, grid);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
  // } Driver Code Ends