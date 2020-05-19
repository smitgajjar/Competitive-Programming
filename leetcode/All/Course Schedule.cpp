// Here, Topological sort is implemented using Kahn's algorithm
vector<int> g[100000];
int s;
int indeg[100000];
int n;
class Solution {
public:
    
    bool topologicalSort() {
        queue<int> q;
        for(int i=0; i<n; i++)
            for(auto &neigh: g[i])
                indeg[neigh]++;
        for(int i=0; i<n; i++)
            if(!indeg[i])
                q.push(i);
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            s++;
            for(auto &neigh: g[node])
            {
                indeg[neigh]--;
                if(!indeg[neigh])
                    q.push(neigh);
            }
        }
        if(s!=n)
            return false;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        n=numCourses;
        for(int i=0; i<n; i++)
        {
            g[i].clear();
            indeg[i]=0;
        }
        s=0;
        for(auto v: prerequisites)
            g[v[1]].push_back(v[0]);
        return topologicalSort();
        
    }
};