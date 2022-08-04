class Solution {
public:
    int majorityElement(vector<int>& v) {
        int n = v.size();
        int count = 1;
        int major = v[0];
        for(int i=1;i<n;i++){
            if(count==0){
                major = v[i];
                count=1;
            }
            else if(v[i]==major){
                count++;
            }
            else{
                count--;
            }
        }
        return major;
    }
};