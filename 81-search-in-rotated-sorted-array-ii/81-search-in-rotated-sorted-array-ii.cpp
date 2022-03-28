class Solution {
    bool bs(int s, int e, int t, vector<int>& v){
        if(s>e)return false;
        if(s==e){
            if(v[s]==t)return true;
            return false;
        }
        int mid = (s+e)/2;
        if(v[mid]==t)
            return true;
        if(v[mid]>t)return bs(s,mid-1,t,v);
        return bs(mid+1,e,t,v);
    }
public:
    bool search(vector<int>& v, int t) {
        int n = v.size();
        int newv = 0;
        for(int i = 1;i<n;i++){
            if(v[i]<v[i-1]){
                newv = i;
            }
        }
        if(newv==0)return bs(0, n-1, t, v);
        return (bs(0,newv-1,t,v) || bs(newv,n-1,t,v));
    }
};