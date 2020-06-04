vector<int> g[100000];
bool inStack[100000];
bool vis[100000];
bool isCycle;
class Solution {
public:
    void dfs(int u)
    {
        vis[u]=true;
        inStack[u]=1;
        for(auto i: g[u])
        {
            if(!vis[i])
                dfs(i);
            else if(inStack[i])
            {
                isCycle=1;
                // return;
            }
        }
        inStack[u]=0;
    }
    
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        // n=numCourses;
        isCycle=0;
        for(int i=0; i<n; i++)
        {
            g[i].clear();
            vis[i]=false;
            inStack[i]=0;
        }
        for(auto v: prerequisites)
            g[v[1]].push_back(v[0]);
        
        for(int i=0; i<n; i++)
            if(!vis[i])
                dfs(i);
        return !isCycle;
    }
};