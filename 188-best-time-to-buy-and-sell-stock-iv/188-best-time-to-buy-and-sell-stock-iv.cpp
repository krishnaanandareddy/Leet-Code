class Solution {
    int ans(vector<int>&v, int n, int i, int ct, bool b, vector<vector<vector<int>>>& dp,int k){
        if(ct==k)return 0;
        if(i>=n)return 0;
        if(dp[i][b][ct]!=-1)return dp[i][b][ct];
        int op1=0,op2=0;
        if(b==0){
            op1=0+ans(v,n,i+1,ct,b,dp,k);
            op2=-v[i]+ans(v,n,i+1,ct,1,dp,k);
        }
        else{
            op1=0+ans(v,n,i+1,ct,b,dp,k);
            op2=v[i]+ans(v,n,i+1,ct+1,0,dp,k);
        }
        dp[i][b][ct]=max(op1,op2);
        return dp[i][b][ct];
    }
public:
    int maxProfit(int k, vector<int>& v) {
        int n = v.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(k,-1)));
        return ans(v,n,0,0,0,dp,k);        
    }
};