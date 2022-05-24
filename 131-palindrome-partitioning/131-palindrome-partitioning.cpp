class Solution {
    bool palin_check(string s, int ps, int pe){
        while(ps<=pe){
            if(s[ps++]!=s[pe--]){
                return false;
            }
        }
        return true;
    }
    void part(int ps,int n, vector<string>& curr, vector<vector<string>>& ans, string s){
        if(ps==n){
            ans.push_back(curr);
            return;
        }
        for(int i=ps;i<n;i++){
            //the partition end is i
            if(palin_check(s,ps,i)==true){
                string temp;
                for(int j=ps;j<=i;j++){
                    temp+=s[j];
                }
                // cout<<temp<<endl;
                curr.push_back(temp);
                part(i+1,n,curr,ans,s);
                curr.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string> curr;
        vector<vector<string>> ans;
        int n = s.size();
        int ps = 0; //partition start
        part(ps,n,curr,ans,s);
        return ans;
    }
};