class Solution {
public:
    int d[4][2]={{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    void dfs(int i, int j, int n, int m, vector<vector<char>>& grid, vector<vector<bool>>& vis)     {
        vis[i][j]=true;
        for(int k=0; k<4; k++) {
            int ni=i+d[k][0], nj=j+d[k][1];
            if(ni>-1 and ni<n and nj>-1 and nj<m and !vis[ni][nj] and (grid[ni][nj]-'0'))
                dfs(ni, nj, n, m, grid, vis);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==0) return 0;
        int n=grid.size(), m=grid[0].size(), island=0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if((grid[i][j]-'0') and !vis[i][j])
                {
                    dfs(i, j, n, m, grid, vis);
                    // cout<<i<<' '<<j<<endl;
                    island++;
                }
        return island;
    }
};