// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

 // } Driver Code Ends
class Solution{
public:
	int count(int N){
        vector<int> ways(N+1);
        ways[0] = 1;
        
        for(int i=2; i<=N; i+=2) {
            for(int j=2; j<=i; j+=2) {
                ways[i] += ways[i-j]*ways[j-2];
            }
        }
        
        return ways[N];
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.count(N) << endl;
    }
    return 0; 
}  // } Driver Code Ends