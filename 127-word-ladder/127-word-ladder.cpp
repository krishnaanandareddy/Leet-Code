class Solution {
public:
    int ladderLength(string s, string e, vector<string>& w) {
        unordered_map<string,int> vis;
        unordered_map<string,int> m;
        for(auto i:w){
            m[i]++;
        }
        if(m[e]==0)return 0;
        queue<string> q;
        int ans = 1;
        q.push(s);
        cout<<q.size();
        while(!q.empty()){
            int n = q.size();
            ans++;
            for(int z=0;z<n;z++){
                string s = q.front();
                q.pop();
                if(vis[s]!=0)continue;
                vis[s]=1;
                int ss = s.size();
                for(int i=0;i<ss;i++){
                    string temp = s;
                    for(int j=0;j<26;j++){
                        temp[i] = 'a'+j;
                        if(vis[temp]==0 && m[temp]>0){
                            q.push(temp);
                        }
                        if(temp==e){
                            return ans;
                        }
                    }
                }
            }
        }
        return 0;
    }
};