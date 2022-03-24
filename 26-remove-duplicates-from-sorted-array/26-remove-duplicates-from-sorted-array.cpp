class Solution {
public:
    int removeDuplicates(vector<int>& v) {
        vector <int> keys;
        int n = v.size();
        for(int i = 1;i<v.size();i++){
            if(v[i]==v[i-1]){
                keys.push_back(i);
            }
        }
        int ans = v.size()-keys.size();
        int j = 0;
        for(int i = 0;i<v.size();i++){
            if(!binary_search(keys.begin(),keys.end(),i)){
                swap(v[i],v[j]);
                j++;
            }
        }
        return ans;
    }
};