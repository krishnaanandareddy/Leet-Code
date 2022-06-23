// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
int md=1e9+7;
	public:
	long long int dp[100001][2];
	int TotalWays(int N)
	{
	    memset(dp,-1,sizeof(dp));
	    long long int k=solve(N,false)%md;
	    return (k*k)%md;
	}
	
	long long int solve(int n,int spaceReq)
	{
	    if(n==0)
	     return 1;
	    if(dp[n][spaceReq]!=-1)
	     return dp[n][spaceReq];
	     
	    if(spaceReq==1)
	    {
	        return dp[n][spaceReq]=solve(n-1,0)%md;
	    }
	    return dp[n][spaceReq]=(solve(n-1,0)%md+solve(n-1,1)%md)%md;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends