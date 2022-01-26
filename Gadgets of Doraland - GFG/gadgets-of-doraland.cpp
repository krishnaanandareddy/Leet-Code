// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    vector<int> TopK(vector<int>& array, int k)
    {
        // code here
        vector<pair<int ,int >> v;
        
        map<int,int> mp ;
        int n=array.size();
        for(int i=0;i<n;i++)
        {
            
            mp[array[i]]++;
        }
        
        for(auto it : mp)
        {
            v.push_back({it.second, it.first});
        }
        sort(v.begin(),v.end() );
        reverse(v.begin(),v.end());
        vector<int> ans;
       

        for(int i=0;i<v.size();i++)
        {
           
            if(k==0)
            break;
            else
            ans.push_back(v[i].second);
            k--;
        }


        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k ;
        cin>>n;
        
        vector<int>array(n);
        
        for(int i=0; i<n; i++)
            cin>>array[i];
            
        cin>>k;
        
        Solution obj;
        vector<int> result = obj.TopK(array,k);
        
        for(int i=0; i<result.size();i++)
            cout<<result[i]<<" ";

        cout<<"\n";

    }
    return 0;
}  // } Driver Code Ends