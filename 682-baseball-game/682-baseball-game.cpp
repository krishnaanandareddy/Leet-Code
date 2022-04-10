class Solution {
public:
    int calPoints(vector<string>& ops) {
        int n = ops.size();
        vector <int> ans;
        int j = 0;
        for(int i = 0; i< n;i++){
            if(ops[i]=="+"){
                ans.push_back(ans[j-1]+ans[j-2]);
                j++;
            }
            else if(ops[i]=="D"){
                ans.push_back(2*ans[j-1]);
                j++;
            }
            else if(ops[i]=="C"){
                // ans[j-1]=0;
                ans.resize(j-1);
                j--;
            }
            else{
                int temp  = stoi(ops[i]);
                ans.push_back(temp);
                j++;
            }
        }
        int res = 0;
        for(auto i:ans){
            res+=i;
        }
        return res;
    }
};