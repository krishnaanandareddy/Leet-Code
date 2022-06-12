class Solution {
public:
    int maximumUniqueSubarray(vector<int>& v) {
        int n =v.size();
        int ans = 0;
        int curr = 0;
        queue<int> q;
        unordered_map<int,int> m;
        for(int i:v){
            m[i]++;
            if(m[i]==2){
                while(1){
                    if(q.front()==i){
                        m[i]=1;
                        curr-=q.front();
                        q.pop();
                        break;
                    }
                    m[q.front()]--;
                    curr-=q.front();
                    q.pop();
                }
            }
            q.push(i);
            curr+=i;
            ans=max(curr,ans);
        }
        return ans;
    }
};