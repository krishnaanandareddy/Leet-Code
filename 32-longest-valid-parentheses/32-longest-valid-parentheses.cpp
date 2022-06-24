class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        stack<int>st;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(i);
            }
            else{
                if(!st.empty()){
                    if(s[st.top()]=='('){
                        st.pop();
                    }
                    else{
                        st.push(i);
                    }
                }
                else{
                    st.push(i);
                }
            }
        }
        int curr = 0;
        int ans = 0;
        int end = n;
        int start;
        while(!st.empty()){
            start = st.top();
            st.pop();
            curr = end - start-1;
            ans = max(ans,curr);
            end = start;
        }
        if(end!=0){
            start = 0;
            curr = end-start;
            ans=max(ans,curr);
        }
        return ans;
    }
};