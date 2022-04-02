// class Solution {
// public:
//     double average(vector<int>& v) {
//         int mn = INT_MAX;
//         int mx = INT_MIN;
//         int n = v.size();
//         float ans = 0;
//         for(int i=0;i<n;i++){
//             if(v[i]<mn){
//                 mn = v[i];
//             }
//             if(v[i]>mx){
//                 mx = v[i];
//             }
//             ans+=v[i];
//         }
//         ans = ans - mn - mx;
//         if(n>2)
//             ans/=(n-2);
//         else ans =0; 
//         float value = (long long)(ans * 100000 + .5);
        
//         return (float)value / 100000;;
//     }
// };
class Solution {
public:
    double average(vector<int>& salary) {
        if(salary.size()==2) return 0;
        int mins = INT_MAX;
        int maxs = INT_MIN;
        double sum = 0;
        for(int x: salary){
            mins = min(mins,x);
            maxs = max(maxs,x);
            sum+=(double)x;
        }
        return (sum - (mins+maxs)) / (salary.size()-2);
    }
};