class Solution {
    int fill(int curr, int n, int prev){
        // cout<<curr<<" "<<prev<<endl;
        if(curr>n)return 1000;
        if(curr==n)return 0;
        if(curr==prev){
            return 1+fill(curr+prev,n,prev);
        }
        int copy = 1+fill(curr,n,curr);
        int paste = 1+fill(curr+prev,n,prev);
        return min(copy,paste);
    }
public:
    int minSteps(int n) { 
        if(n==1)return 0;
        return 1+fill(1,n,1);
    }
};