class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        set <pair<int, int>> s;
        for (int i=0;i<mat.size();i++){
            int count = 0;
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1)count++;
                else break;
            }
            s.insert({count,i});
        }
        int count = 0;
        vector<int> ans;
        for(auto i:s){
            if(count<k){
                count++;
                ans.push_back(i.second);
            }
            if(count>=k)break;
        }
        return ans;
    }
};