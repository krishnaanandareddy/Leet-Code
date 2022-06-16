// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    bool checker(unordered_map<int,bool>umap){
        for(auto i:umap)
            if(i.second == false)return false;
        
        return true;
    }
    public:
    int findSubString(string str)
    {
        // Your code goes here
        int arr[256] = {0};
        unordered_map<int,bool>umap;
        
        for(auto i:str)
            umap[i] = false;
            
        int i=0, j=0;
        
        int ans = INT_MAX;
        bool flag = false;
        
        while(i<str.length()){
            arr[str[i]]++;
            umap[str[i]] =true;
            
            if(!flag){
                if(checker(umap))
                    flag = true;
            }
              
            if(flag){  
                while(arr[str[j]]>1){
                    arr[str[j]]--;
                    j++;
                }
                ans = min(ans,i-j+1);
            }
                
            
            
            i++;
            
            
        }
        
        
        return ans;
        
    }
};

// { Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}  // } Driver Code Ends