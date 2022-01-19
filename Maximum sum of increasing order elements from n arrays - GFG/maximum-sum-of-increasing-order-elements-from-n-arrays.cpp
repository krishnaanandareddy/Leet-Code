// { Driver Code Starts
// CPP program to find maximum sum
// by selecting a element from n arrays
#include<bits/stdc++.h>

using namespace std;

// To calculate maximum sum by
// selecting element from each array
int maximumSum( int n,int m, vector<vector<int>> &a);



// Driver program to test maximumSum
int main() {
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        vector<vector<int>> arr(n, vector<int>(m,0));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            cin>>arr[i][j];
            
        cout << maximumSum(n,m,arr)<<endl;
    
    }
    return 0;

}
// } Driver Code Ends


int maximumSum( int n,int m, vector<vector<int>> &a) {
    
    int mx = 0;
    int sum = 0;
    for(int i=n-1;i>=0;i--){
        int temp = 0;
        bool ok = 0;
        for(int j=0;j<m;j++){
            if(i == n-1){
                ok = 1;
                mx = max(mx , a[i][j]);
            }else{
                if(mx > a[i][j]){
                    ok = 1;
                    temp = max(temp, a[i][j]);
                }
            }
        }
        if(i!=n-1)mx = temp;
        if(ok == 0){
            return 0;
        }
        sum += mx;
    }
    return sum;
}