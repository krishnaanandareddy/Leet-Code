class Solution {
public:
    bool canConstruct(string s1, string s2) {
        int n = s2.size();
        unordered_map<char,int> m;
        for(int i=0;i<n;i++)m[s2[i]]++;
        n= s1.size();
        for(int i=0;i<n;i++){
            m[s1[i]]--;
            if(m[s1[i]]<0)return 0;
        }
        return 1;
    }
};