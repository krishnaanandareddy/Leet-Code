class Solution {
    bool bs(int row, vector<vector<int>>& v, int t, int s, int e){
        if(s>e)return false;
        if(s==e){
            if(v[row][s]==t)return true;
            return false;
        }
        int mid=(s+e)/2;
        if(v[row][mid]==t)return true;
        if(v[row][mid]>t)return bs(row,v,t,s,mid-1);
        return bs(row,v,t,mid+1,e);
    }
public:
    bool searchMatrix(vector<vector<int>>& v, int t) {
        int n = v.size();
        int m = v[0].size();
        if(v[0][0]>t)return false;
        if(v[n-1][m-1]<t)return false;
        int row;
        int s = 0;
        int e = n-1;
        bool findr = 0;
        while(findr==0){
            if(s>e)return false;
            int mid = (s+e)/2;
            if(v[mid][0]<=t && v[mid][m-1]>=t){
                row = mid;
                findr = 1;
            }
            else{
                if(v[mid][0]>t){
                    e=mid-1;
                }
                if(v[mid][m-1]<t){
                    s=mid+1;
                }
            }
        }
        s=0;
        e=m-1;
        return bs(row,v,t,s,e);
    }
};