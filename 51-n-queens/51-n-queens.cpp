class Solution {
        void check(int c, int n, vector<string>& temp, vector<vector<string>>& ans, vector<int>& ud, vector<int>& ld, vector<int>& row){
        if(c==n){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<n;i++){
            int udc = n-1 + c-i;
            int ldc = i+c;
            int rc = i;
            if(ud[udc]==1 || ld[ldc]==1 || row[rc]==1)continue;
            ud[udc]=1;
            ld[ldc]=1;
            row[rc]=1;
            temp[i][c]='Q';
            check(c+1,n,temp,ans,ud,ld,row);
            temp[i][c]='.';
            ud[udc]=0;
            ld[ldc]=0;
            row[rc]=0;
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> temp;
        string s(n,'.');
        for(int i=0;i<n;i++)temp.push_back(s);
        vector<int> ud(2*n-1,0);
        vector<int> ld(2*n-1,0);
        vector<int> row(n,0);
        check(0,n,temp,ans,ud,ld,row);
        return ans;
    }
};