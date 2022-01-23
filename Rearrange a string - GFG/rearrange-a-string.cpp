// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
public:
    string arrangeString(string str)
    {
        string ans;
        int sum = 0;

        for (int i = 0; i < str.size(); i++)
        {
            if (isalpha(str[i]))
                ans.push_back(str[i]);
            else
                sum += str[i] - '0';
        }
        sort(ans.begin(), ans.end());
        ans += to_string(sum);
        return ans;
    }
};
// { Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout <<ob.arrangeString(s) << endl;
    }
return 0;
}

  // } Driver Code Ends