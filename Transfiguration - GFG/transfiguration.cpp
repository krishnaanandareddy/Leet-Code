// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    
    public:
    int transfigure (string A, string B)
    {
          int count=0;
       
       
       
    	if(A.length()!=B.length())
    	return -1;
    	else
    	{
    	 
    	 unordered_map<char,int> m;
    	 
    	 for(int i=0;i<A.length();i++)
    	 {
    	     m[A[i]]++;
    	 }
    	 
    	 for(int j=0;j<B.length();j++)
    	 {
    	     m[B[j]]--;
    	 }
    	 
    	 for(int i=0;i<A.length();i++)
    	 {
    	     if(m[A[i]]>0)
    	     return -1;
    	 }
    	   
    	   
    	    int i=A.length()-1;
    	    int j=A.length()-1;
    	    
    	    while(i>=0 && j>=0)
    	    {
    	        
    	        if(A[i]!=B[j])
    	        {
    	            i--;
    	            count++;
    	        }
    	        else
    	        {
    	            i--;
    	            j--;
    	        }
    	        
    	        
    	    }
    	    
    	   return count; 
    	}
    }
};


// { Driver Code Starts.


int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution obj;
        cout << obj.transfigure (A, B) << endl;
    }
}  // } Driver Code Ends