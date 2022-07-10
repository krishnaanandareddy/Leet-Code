class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& v, int k) {
        int n = v.size();
        deque<int> q;
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(!q.empty() && q.front()==i-k)q.pop_front();
            while(!q.empty()&& v[i]>=v[q.back()])q.pop_back();
            q.push_back(i);
            if(i>=k-1)ans.push_back(v[q.front()]);
        }
        return ans;
    }
};