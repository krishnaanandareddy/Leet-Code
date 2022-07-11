// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


vector<int> reaching_height(int n, int a[]) ;

int main() {
	int t;
	cin >> t;
	while (t-- > 0) {
	    int n; 
	    cin >> n;
	    int a[n];
	    for (int i = 0; i < n; i++) 
	        cin >> a[i];
	    vector<int> v;
	    v = reaching_height(n,a);
	
	    if(v.size()==1 and v[0] == -1){
	        cout << "Not Possible\n";
	    }
	    else{
	    for(int i:v)
	        cout << i << " ";
	    cout << endl;}
	    
	}
	return 0;
}// } Driver Code Ends


//User function Template for C++

vector<int> reaching_height(int n, int a[]) {

    sort(a, a+n);
    int i = n-1, j = 0;
    vector<int> ans;
    int flag = 1;
    while( (i>=j) )
    {
        if(flag)
        {
            ans.push_back(a[i]);
            i--;
        }
        else if( (flag == 0))
        {
            ans.push_back(a[j]);
            j++;
        }
        flag = 1 - flag;
    }

    int sum = 0;
    for(i=0; i<ans.size(); i++)
    {
        if(i%2) sum -= ans[i];
        else sum += ans[i];
        
        if(sum == 0)
            return {-1};
    }
    return ans;
}
