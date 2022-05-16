class Solution {
public:
    void rotate(vector<vector<int>>& v) {
        int n = v.size();
        int temp = n;
        int diff = 0;
        while(temp>1){
            for(int i=diff;i<n-diff-1;i++){
                int p1 = v[diff][i];
                int p2 = v[i][n-1-diff];
                int p3 = v[n-1-diff][n-1-i];
                int p4 = v[n-1-i][diff];
                v[diff][i] = p4;
                v[i][n-1-diff] = p1;
                v[n-1-diff][n-1-i] = p2;
                v[n-1-i][diff] = p3;
            }
            diff = diff+1;
            temp = temp-2;
            // cout<<temp<<endl;
        }
        return;        
    }
};