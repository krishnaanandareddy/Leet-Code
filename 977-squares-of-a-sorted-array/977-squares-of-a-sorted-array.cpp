class Solution {
public:
     vector<int> sortedSquares(vector<int>& a) {
        int n=a.size();
        int start=0,end=n-1,vend=n-1;
        vector<int>v(n,0);
        for(int i=0;i<n;i++)
        {
            if(abs(a[start])>abs(a[end]))
            {
                v[vend]=a[start]*a[start];
                vend--;
                start++;
            }
            else
            {
                v[vend]=a[end]*a[end];
                vend--;
                end--;
            }
        }
        return v;
        
    }
};