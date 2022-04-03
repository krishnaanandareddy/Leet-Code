class Solution {
public:
    int searchInsert(vector<int>& nums, int t) {
        int s = 0;
        int e = nums.size() - 1;
        int mid;
        int n = nums.size();
        while(s<=e){
            mid = (s+e)/2;
            if(nums[mid] == t){
                break;
            }
            if(nums[mid] >t){
                if(mid-1 < 0) return 0;
                if(nums[mid-1]<t){
                    break;
                }
                e = mid-1;
            }
            if(nums[mid] < t){
                if(mid+1 >= n)return n; 
                if(nums[mid+1]>t){
                    mid++;
                    break;
                }
                s = mid+1;
            }
        }
        return mid;
    }
};