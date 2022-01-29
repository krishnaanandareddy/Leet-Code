// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
   public:
  
   string reverseWords(string s) 
   { 
   int j;
   reverse(s.begin(), s.end());
   int n = s.size();
   for (int i = 0; i < n; i++)
   {
       if (s[i] != 46)
       {
           j = i;
           for (; j < n && s[j] != 46; j++)
           {
           }
           reverse(s.begin() + i, s.begin() + j);
           i = j - 1;
       }
   }
   return s;
   } 
}; 
// { Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}  // } Driver Code Ends