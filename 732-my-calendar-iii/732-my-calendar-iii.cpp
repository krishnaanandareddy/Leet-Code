class MyCalendarThree {
    map<int,int> m;
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        m[start]++;
        int ans = 0;
        int curr = 0;
        m[end]--;
        for(auto i:m){
            curr+=i.second;
            ans = max(ans,curr);
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */