class Solution {
public:
    vector<int> intersect(vector<int>& v1, vector<int>& v2) {
        int n1 = v1.size();
        int n2 = v2.size();
        unordered_map<int,int>m;
        vector<int> ans;
        for(int i=0;i<n1;i++){
            m[v1[i]]++;
        }
        for(int i=0;i<n2;i++){
            if(m[v2[i]]==0)continue;
            ans.push_back(v2[i]);
            m[v2[i]]--;
        }
        return ans;
    }
};