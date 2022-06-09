class Solution {
public:
    int longestCommonSubsequence(string &a, string &b) {
        int n1 = a.size(), n2 = b.size();
        vector<vector<int>> m(n1+1,vector<int>(n2+1,0));
        for (auto i = 0; i < a.size(); ++i)
            for (auto j = 0; j < b.size(); ++j)
                m[i + 1][j + 1] = a[i] == b[j] ? m[i][j] + 1 : max(m[i + 1][j], m[i][j + 1]);
        int n = m[a.size()][b.size()];
        int i=n1,j=n2,index = n-1;
        string ans = "";
        for(int i=0;i<n;i++){
            ans+="$";
        }  
        while(i>0 && j>0){
            if(a[i-1]==b[j-1]){
                ans[index]=a[i-1];
                i--;
                j--;
                index--;
            }
            else if(m[i][j]==m[i-1][j]){
                i--;
            }
            else{
                j--;
            }
        }
        cout<<ans<<endl;
        return n;
    }
};