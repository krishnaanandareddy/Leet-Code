class Solution {
public:
    int longestSubsequence(string s, int k) {
        string bk = bitset<32>(k).to_string();
        // cout<<bk;
        
        
        
        
        int n1 = s.size();
        int n2 = bk.size();
        for(int i=0;i<n2;i++){
            if(bk[i]=='1'){
                n2 = n2-i;
                break;
            }
        }
        int i1=n1-1;
        int i2=n2-1;
        if(i1<i2){
            return n1;
        }
        
        int temp=0;
        int ans = 0;
        long long p = 1;
        bool g =0;
        for(int i=n1-1;i>=0;i--){
            if(g==1){
                if(s[i]=='0')ans++;
                continue;
            }
            if(s[i]=='1'){
                temp+=p;
            }
            if(temp>k){
                g=1;
                cout<<"tempk";
                continue;
            }
            ans++;
            if(ans>=n2){
                g=1;
                cout<<"ans";
            }
            long long t = 2;
            p*=t;
            cout<<temp<<" ";
        }
        return ans;
    }
};