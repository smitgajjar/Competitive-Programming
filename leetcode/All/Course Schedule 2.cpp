bool isCycle;
bool vis[100000], inStack[100000];
vector<int> g[100000], order;

class Solution {
public:
    void topologicalSortUsingDfs(int s){
        dfs(s);
    }
    void dfs(int s)
    {
        vis[s]=1;
        inStack[s]=1;
        for(auto i: g[s])
        {
            if(vis[i] and inStack[i])
                isCycle=1;
            if(!vis[i])
                dfs(i);
        }
        inStack[s]=0;
        order.push_back(s);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i=0; i<numCourses; i++)
        {
            g[i].clear();
            vis[i]=false;
            inStack[i]=false;
        }
        order.clear();
        isCycle=false;
        for(auto v: prerequisites)
            g[v[1]].push_back(v[0]);
        for(int i=0; i<numCourses; i++)
            if(!vis[i])
                topologicalSortUsingDfs(i);
        if(isCycle)
            return {};
        reverse(order.begin(), order.end());
        return order;
        
    }
};