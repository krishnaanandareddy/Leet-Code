class Solution {
    bool r=0;
    bool d=0;
    bool l=0;
    bool u=0;
    vector<int> next(int x,int y,vector<vector<int>>& v,int count){
        if(l&& d&& r&& u && count>=4)return {x,y};
        if(r==1){
            vector<int> temp = nextr(x,y,v);
            count++;
            if(temp[1]!=y){
                r=1;d=0;l=0;u=0;
                return {x,y+1};
            }
            d=1;
        }
        if(d==1){
            vector<int> temp = nextd(x,y,v);
            count++;
            if(temp[0]!=x){
                r=0;d=1;l=0;u=0;
                return {x+1,y};
            }
            l=1;
        }
        if(l==1){
            vector<int> temp = nextl(x,y,v);
            count++;
            if(temp[1]!=y){
                r=0;d=0;l=1;u=0;
                return {x,y-1};
            }
            u=1;
        }
        if(u==1){
            vector<int> temp = nextu(x,y,v);
            cout<<temp[0]<<temp[1]<<endl;
            count++;
            if(temp[0]!=x){
                r=0;d=0;l=0;u=1;
                return {x-1,y};
            }
            r=1;
        }
        return next(x,y,v,count);
        
    }
    vector<int> nextr(int x,int y,vector<vector<int>>& v){
        int n = v.size();
        int m = v[0].size();
        if(y+1 < m && v[x][y+1]!=INT_MAX){
            return{x,y+1};
        }
        else{
            return {x,y};
        }
    }
    vector<int> nextd(int x,int y,vector<vector<int>>& v){
        int n = v.size();
        int m = v[0].size();
        if(x+1 < n && v[x+1][y]!=INT_MAX){
            return{x+1,y};
        }
        else{
            return {x,y};
        }
    }
    vector<int> nextl(int x,int y,vector<vector<int>>& v){
        int n = v.size();
        int m = v[0].size();
        if(y-1 >=0 && v[x][y-1]!=INT_MAX){
            return{x,y-1};
        }
        else{
            return {x,y};
        }
    }
    vector<int> nextu(int x,int y,vector<vector<int>>& v){
        int n = v.size();
        int m = v[0].size();
        if(x-1 >=0 && v[x-1][y]!=INT_MAX){
            return{x-1,y};
        }
        else{
            return {x,y};
        }
    }
    
public:
    vector<int> spiralOrder(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();
        vector<int> ans;
        int i = 0;
        int j = 0;
        r=1;
        while(v[i][j]!=INT_MAX){
            ans.push_back(v[i][j]);
            v[i][j]=INT_MAX;
            vector<int> temp = next(i,j,v,0);
            i=temp[0];
            j=temp[1];
            cout<<i<<" "<<j<<" "<<v[i][j]<<endl;
        }
        return ans;
    }
};