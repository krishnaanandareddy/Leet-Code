class Solution {
    int bs(int s, int e, int val, vector<int>& nums){
        if(s==e){
            if(nums[s]==val)return s;
            return -1;
        }
        if(s>e)return -1;
        int mid = (s+e)/2;
        if(nums[mid]==val)return mid;
        if(nums[mid]>val)return bs(s,mid-1,val,nums);
        return bs(mid+1,e,val,nums);
    }
public:
    int search(vector<int>& nums, int target) {
        int e = nums.size()-1;
        int s = 0;
        return bs(s,e,target,nums);
    }
};