class Solution {
    unordered_map<int,int> m;
    int find(int u,vector<int>&par){
        if(par[u]==u)return u;
        return par[u] = find(par[u],par);
    }
    void combine(int u, int v, vector<int>&par, vector<int>&rank){
        u=find(u,par);
        v=find(v,par);
        if(u==v)return;
        if(rank[u]>rank[v]){
            par[v]=u;
        }
        else if(rank[u]<rank[v]){
            par[u]=v;
        }
        else{
            par[u]=v;
            rank[u]++;
        }
    }
public:
    int longestConsecutive(vector<int>& v) {
        int n = v.size();
        if(n==0)return 0;
        vector<int>rank(n,1);
        vector<int>par(n,-1);
        for(int i=0;i<n;i++){
            par[i]=i;
            if(m[v[i]]==0){
                m[v[i]]=i+1;
            }
            else{
                continue;
            }
            int prev = v[i]-1;
            int next = v[i]+1;
            if(m[prev]!=0){
                int pind = m[prev]-1;
                combine(i,pind,par,rank);
            }
            if(m[next]!=0){
                int nind = m[next]-1;
                combine(i,nind,par,rank);
            }
        }
        unordered_map<int,int> freq;
        int ans = 1;
        for(int i=0;i<n;i++){
            int p = find(i,par);
            freq[p]++;
            ans = max(ans,freq[p]);
        }
        return ans;
    }
};