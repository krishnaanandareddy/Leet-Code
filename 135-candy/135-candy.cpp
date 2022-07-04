class Solution {
public:
    int candy(vector<int>& v) {
        int n = v.size();
        vector<int>c(n,1); 
        multimap<int,int> m;
        for(int i=0;i<n;i++){
            m.insert({v[i],i});
        }
        for(auto p:m){
            int i = p.second;
            int rating = p.first;
            int n1 = rating;
            int n2 = rating;
            if(i+1<n){
                n1 = v[i+1];
            }
            if(i-1>=0){
                n2 = v[i-1];
            }
            if(rating>n1){
                c[i] = max(c[i],c[i+1]+1);
            }
            if(rating>n2){
                c[i] = max(c[i],c[i-1]+1);
            }
            // cout<<c[i]<<" "<<i<<" "<<n1<<" "<<n2<<endl;
        }
        int ans = 0;
        for(auto i:c)ans+=i;
        return ans;
    }
};