class Solution {
public:
    vector<int> plusOne(vector<int>& A) {
        int n = A.size();
        int temp = 1;
        bool in = 0;
        for(int i=n-1;i>=0;i--){
            if(A[i]+temp<=9){
                A[i]++;
                break;
            }
            else{
                A[i] = A[i]+temp-10;
                if(i==0){
                   in = 1;
                }
            }
        }
        if(in==1){
            A.push_back(0);
            for(int i=n;i>0;i--){
                A[i]=A[i-1];
            }
            A[0]=1;
        }
        return A;
    }
};