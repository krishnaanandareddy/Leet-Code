class Solution {
    static bool comp(vector<int> v1, vector<int> v2){
        return (v1[1] > v2[1]);
    }
public:
    int maximumUnits(vector<vector<int>>& v, int size) {
        sort(v.begin(),v.end(),comp);
        int ans = 0;
        for(auto a : v){
            if(size>=a[0]){
                ans+=a[0]*a[1];
                size-=a[0];
                // cout<<a[0]<<" "<<a[1]<<endl;
            }
            else if(size>0){
                ans+=size*a[1];
                size=0;
                // cout<<size<<" "<<a[1]<<endl;
            }
            else{
                break;
            }
        }
        return ans;
    }
};