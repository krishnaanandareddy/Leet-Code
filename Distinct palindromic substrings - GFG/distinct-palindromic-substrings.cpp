// { Driver Code Starts
// C++ program to find all distinct palindrome sub-strings
// of a given string
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++
class Solution{
 public:
   int palindromeSubStrs(string s) {
       int n = s.length();
       bool dp[n][n] = {false};
       unordered_set<string> set;
       for(int len = 1; len <= n; len ++) {
           for(int i = len - 1; i < n; i ++) {
               int start = i - len + 1;
               int end = i;
               if(s[start] == s[end] && (start + 1 > end - 1 || dp[start + 1][end - 1])) {
                   dp[start][end] = true;
                   set.insert(s.substr(start, end - start + 1));
               }
           }
       }
       return set.size();
   }
};

// { Driver Code Starts.

// Driver program
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.palindromeSubStrs(str) << endl;
    }
    return 0;
}
  // } Driver Code Ends