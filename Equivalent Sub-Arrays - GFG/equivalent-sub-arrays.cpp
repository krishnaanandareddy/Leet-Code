// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
int countDistinctSubarray(int arr[], int n)
    {
        //code here. 
        int cnt = 0 ;
        map<int,int> mp1 ;
        for(int i = 0 ; i < n ; i++ )
        {
            if( mp1[arr[i]] == 0 )
            {
                cnt++ ;
                mp1[arr[i]]++ ;
            }
        }
        
        map<int,int> mp2 ;
        
        int curCnt = 1 , ans = 0 ;
        int i = 0, j = 0;
        
        mp2[arr[0]]++ ;
        
        while( j < n )
        {
            if( curCnt == cnt )
            {
                ans += (n - j ) ;
                
                mp2[arr[i]]-- ;
                
                if( mp2[arr[i]] == 0 ) curCnt -= 1 ;
                i++ ;
            }
            else 
            {
                j++ ;
                
                if( j >= n ) break ;
                
                mp2[arr[j]]++ ;
                if( mp2[arr[j]] == 1 ) curCnt += 1 ;
            }
        }
        return ans ;
    }
};


// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;	
		cout<<ob.countDistinctSubarray(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends