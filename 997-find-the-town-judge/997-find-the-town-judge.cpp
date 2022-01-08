class Solution {
public:
    int findJudge(int n, vector<vector<int>>& v) {
        map <int,int> m;
        for(int i=0;i<v.size();i++){
            m[v[i][0]]--;
            m[v[i][1]]++;
        }
        for(int i=1;i<=n;i++){
            if(m[i]==n-1){
                return i;
            }
        }
        return -1;
    }
};