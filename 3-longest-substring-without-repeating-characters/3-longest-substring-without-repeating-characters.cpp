class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map <char,int> m;
        queue<char> q;
        int ans = 0;
        int temp = 0;
        for(char i:s){
            m[i]++;
            if(m[i]==2){
                while(1){
                    if(q.front()==i){
                        q.pop();
                        q.push(i);
                        m[i]=1;
                        temp = q.size();
                        break;
                    }
                    m[q.front()]=0;
                    q.pop();
                }
            }
            else{
                temp+=1;
                ans = max(ans,temp);
                cout<<temp;
                q.push(i);
            }
        }
        return ans;
    }
};