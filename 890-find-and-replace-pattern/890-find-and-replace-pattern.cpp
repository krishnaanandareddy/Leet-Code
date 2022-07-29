class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string p) {
        vector<string> ans;
        for(auto s:words){
            unordered_map<char,char> m;
            unordered_map<char,int> used;
            int n = s.size();
            bool ok = 1;
            for(int i=0;i<n;i++){
                char c1 = p[i];
                char c2 = s[i];
                if(m.find(c1)!=m.end()){
                    if(m[c1]!=c2){
                        ok=0;
                        break;
                    }
                }
                else if(used[c2]>0){
                    ok = 0;
                    break;
                }
                else{
                    m[c1]=c2;
                    used[c2]++;
                }                
            }
            if(ok)ans.push_back(s);
        }
        return ans;
    }
};