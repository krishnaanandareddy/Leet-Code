class Solution {
public:
    vector<int> twoSum(vector<int>& v, int target) {
        vector<int> arr = v;
        sort(v.begin(),v.end());
        int n = v.size();
        int start =0;
        int end = n-1;
        while(v[start]+v[end] !=target){
            int sum = v[start]+v[end];
            if(sum>target){
                end--;
            }
            else if(sum<target){
                start++;
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(v[start]==arr[i]){
                start=i;
                break;
            }
        }
        for(int i=0;i<n;i++){
            if(v[end]==arr[i] && i!=start){
                end=i;
                break;
            }
        }
        ans.push_back(start);
        ans.push_back(end);
        return ans;
    }
};