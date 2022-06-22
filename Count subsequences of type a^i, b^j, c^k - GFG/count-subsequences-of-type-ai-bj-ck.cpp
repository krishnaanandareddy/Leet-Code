// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function template 

class Solution{
  public:
    // s : given string
    // return the expected answer
int mod = 1e9 + 7;
    int helper(string &a, string b, int n1, int n2, vector<vector<int>> &dp) {
        if (dp[n1][n2] != -1)
            return dp[n1][n2];
        if (n2 == 0)
            return dp[n1][n2] = 1;
        if (n1 == 0)
            return dp[n1][n2] = 0;
        int ans = 0;
        if (a[n1 - 1] == b[n2 - 1]) {
            ans += helper(a, b, n1 - 1, n2 - 1, dp);
            ans %= mod;
            ans += helper(a, b, n1 - 1, n2, dp);
            ans %= mod;
        }
        ans += helper(a, b, n1 - 1, n2, dp);
        ans %= mod;
        return dp[n1][n2] = ans;
    }
    int fun(string &s) {
        //code here
        
        string str = "abc";
        int n1 = s.size();
        int n2 = 3;
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
        return helper(s, str, n1, n2, dp);
    }
};

// { Driver Code Starts.
 
int main()
 {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.fun(s)<<endl;
    }
	return 0;
}  // } Driver Code Ends