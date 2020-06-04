const int N=2001;
bool vis[N];
bool color[N];
bool flag;
vector<int> g[N];


class Solution {
public:
    void dfs(int u)
    {
        vis[u]=1;
        for(auto v: g[u])
        {
            if(!vis[v])
            {
                color[v]=!color[u];
                dfs(v);
            }
            else if(color[v]==color[u])
            {
                flag=0;
                return;
            }
        }
        
    }
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        for(int i=1; i<=N; i++)
        {
            g[i].clear();
            color[i]=0;
            vis[i]=0;
        }
        flag=1;
        for(int i=0; i<dislikes.size(); i++)
        {
            g[dislikes[i][0]].push_back(dislikes[i][1]);
            g[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        for(int i=1; i<=N; i++)
        {
            if(!vis[i])
                dfs(i);
            if(!flag)
                return false;
        }
        return true;
    }
};