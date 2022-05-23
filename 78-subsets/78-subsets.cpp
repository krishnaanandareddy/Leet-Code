class Solution {
    void add(int ci, vector<int>& temp, vector<vector<int>>& ans, vector<int>& nums, int n){
        if(ci>=n){
            ans.push_back(temp);
            return;
        }        
        temp.push_back(nums[ci]);
        add(ci+1,temp,ans,nums,n);
        temp.pop_back();
        add(ci+1,temp,ans,nums,n);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {     
        vector<int> temp;
        vector<vector<int>> ans;
        int n = nums.size();
        add(0,temp,ans,nums,n);
        return ans;
    }
};