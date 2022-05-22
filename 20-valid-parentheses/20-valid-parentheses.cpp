class Solution {
public:
    bool isValid(string v) {
        stack <char> st;
        int n = v.size();
        for(int i=0;i<n;i++){
            char temp = v[i];
            if(st.empty()){
                st.push(v[i]);
            }
            else{
                char t=st.top();
                if((t=='('&&temp==')')||(t=='{'&&temp=='}')||(t=='['&&temp==']')){
                    st.pop();
                }
                else{
                    st.push(temp);
                }
            }
        }
        if(st.empty())return true;
        return false;
    }
};