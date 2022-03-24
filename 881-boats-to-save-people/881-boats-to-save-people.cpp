class Solution {
public:
    int numRescueBoats(vector<int>& v, int l) {
        sort(v.begin(),v.end());
        int i=0; 
        int j=v.size()-1;
        int ans = 0;
        while(i<=j){
            if(i==j){
                ans++;
                break;
            }
            if(v[i]+v[j]<=l){
                ans++;
                i++;
                j--;
            }
            else{
                ans++;
                j--;
            }
        }
        return ans;
    }
};