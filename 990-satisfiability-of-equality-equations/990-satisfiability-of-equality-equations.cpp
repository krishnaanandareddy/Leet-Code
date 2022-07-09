class Solution {
    unordered_map<char,char> f;
    char find(char u){
        if(!f.count(u)){
            f[u]=u;
            return u;
        }
        if(f[u]==u)return u;
        return f[u]=find(f[u]);
    }
    void combine(char u, char v){
        u=find(u);
        v=find(v);
        if(u==v)return;
        f[u]=v;
    }
public:
    bool equationsPossible(vector<string>& v) {
        for(auto s:v){
            if(s[1]=='='){
                combine(s[0],s[3]);
            }
        }
        for(auto s:v){
            if(s[1]=='!'){
                if(find(s[0])==find(s[3]))return 0;
            }
        }        
        return 1;
    }
};