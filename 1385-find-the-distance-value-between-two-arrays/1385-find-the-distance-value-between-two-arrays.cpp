class Solution {
public:
    int findTheDistanceValue(vector<int>& v1, vector<int>& v2, int d) {
        sort(v2.begin(),v2.end());
        int n1 = v1.size();
        int n2 = v2.size();
        int ans=0;
        for(int i=0;i<n1;i++){
            bool f = 1;            
            for(int j=0;j<n2;j++){
                if(abs(v1[i]-v2[j])<=d){
                    f=0;
                    break;
                }
            }
            if(f==1)ans++;
        }
        return ans;
    }
};