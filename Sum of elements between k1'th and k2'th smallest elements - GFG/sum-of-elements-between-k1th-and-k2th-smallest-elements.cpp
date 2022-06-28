// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2)
    {
        // Your code goes here
        priority_queue<long long> pq;
        for (long long i = 0; i < K2; i++) pq.push(A[i]);
        for (long long i = K2; i < N; i++) {
            if (pq.top() > A[i]) {
                pq.pop();
                pq.push(A[i]);
            }
        }
        long long ans = 0;
        while (pq.size() > K1 + 1) {
            pq.pop();
            ans += pq.top();
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        cin>>n;
        long long a[n+5];
        for(int i =0;i<n;i++)
            cin >> a[i];
        
        long long k1, k2;
        cin >> k1 >> k2;
        Solution ob;
        cout << ob.sumBetweenTwoKth(a, n, k1, k2) << endl;
        
    }
	return 0;
}
  // } Driver Code Ends