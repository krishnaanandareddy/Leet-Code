class Solution {
public:
    vector<int> asteroidCollision(vector<int>& v) {
        stack <int> s;
        for(auto i:v){
            if(s.empty())s.push(i);
            else{
                if(s.top()*i>0){
                    s.push(i);
                }
                else{
                    if(abs(i)==abs(s.top())){
                        if(i>0)s.push(i);
                        else s.pop();
                    }
                    else if(s.top()<0 && i>0){
                        s.push(i);
                    }
                    else if(s.top()>0 && i<0){
                        while(!s.empty() && abs(s.top())<abs(i) && s.top()>0){
                            s.pop();
                        }
                        if(s.empty())s.push(i);
                        else if(abs(i)==abs(s.top())){
                            if(s.top()>0)s.pop();
                            else s.push(i);
                        }
                        else if(s.top()<0){
                            s.push(i);
                        }
                    }
                }
            }
        }
        int n = s.size();
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--){
            ans[i]=s.top();
            s.pop();
        }
        return ans;
    }
};