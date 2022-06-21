class Solution {
public:
    int furthestBuilding(vector<int>& h, int b, int l) {
        int n = h.size();
        priority_queue<int>pq;
        for(int i=1;i<n;i++){
            if(h[i]-h[i-1]>0){
                pq.push(h[i-1]-h[i]);
            }
            if(pq.size()>l){
                b+=pq.top();
                pq.pop();
            }
            if(b<0)return i-1;
        }
        return n-1;
    }
};