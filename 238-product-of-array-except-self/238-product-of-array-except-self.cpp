class Solution {
public:
    vector<int> productExceptSelf(vector<int>& v) {
        int n = v.size();
        vector<long long int> p(n,1),s(n,1);
        
        for(int i=0;i<n;i++){
            p[i]=v[i];
            s[i]=v[i];
        }
        for(int i=1;i<n;i++){
            p[i]*=p[i-1];
            // cout<<p[i]<<" ";
        }
        // cout<<endl;
        for(int i=n-2;i>=0;i--){
            s[i]*=s[i+1];
            // cout<<s[i]<<" ";
        }
        vector<int> ans(n,1);
        for(int i=0;i<n;i++){
            if(i==0)ans[i]=s[i+1];
            else if(i==n-1)ans[i]=p[i-1];
            else{
                ans[i] = p[i-1]*s[i+1];
            }
        }
        return ans;
    }
};