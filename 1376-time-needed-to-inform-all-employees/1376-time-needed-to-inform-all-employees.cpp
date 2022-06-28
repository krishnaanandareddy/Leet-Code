class Solution {
    int ans = 0;
    void dfs(int curr, int i, vector<int>& t, vector<vector<int>>& g){
        if(curr>ans)ans=curr;
        curr+=t[i];
        if(g[i].size()==0)return;
        for(int node:g[i]){
            dfs(curr,node,t,g);
        }
    }
public:
    int numOfMinutes(int n, int h, vector<int>& manager, vector<int>& t) {
//         these braces after vector<int>() are compulsory
//         IMPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP
        vector<vector<int>> g(n,vector<int>());
        for(int i=0;i<n;i++){
            if(manager[i]!=-1)
                g[manager[i]].push_back(i);
        }
        dfs(0,h,t,g);
        return ans;
    }
};