class Solution {
public:
    int removeDuplicates(vector<int>& v) {
        vector <int> keys;
        int n = v.size();
        int index = 1;
        for(int i = 1;i<v.size();i++){
            if(v[i]!=v[i-1]){
                v[index] = v[i];
                index++;
            }
        }
        return index;
    }
};