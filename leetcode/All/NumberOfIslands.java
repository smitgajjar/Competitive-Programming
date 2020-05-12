import java.io.*;
import java.util.*;

class Pair {
    public int f, s;
    Pair(int x, int y) {
        f=x;
        s=y;
    }
}
class NumberOfIslands {

    // Implement your solution by completing the below function

    
    void dfs(Pair src, int n, int m, char[][] grid, boolean[][] vis) {
        vis[src.f][src.s] = true;

        if(src.f-1>=0 && !vis[src.f-1][src.s] && grid[src.f-1][src.s]=='1')
            dfs(new Pair(src.f-1, src.s), n, m, grid, vis);
        if(src.f+1<n && !vis[src.f+1][src.s] && grid[src.f+1][src.s]=='1')
            dfs(new Pair(src.f+1, src.s), n, m, grid, vis);
        if(src.s-1>=0 && !vis[src.f][src.s-1] && grid[src.f][src.s-1]=='1')
            dfs(new Pair(src.f, src.s-1), n, m, grid, vis);
        if(src.s+1<m && !vis[src.f][src.s+1] && grid[src.f][src.s+1]=='1')
            dfs(new Pair(src.f, src.s+1), n, m, grid, vis);
    }
    public int numIslands(char[][] grid) {
        int n=grid.length;
        int m=grid[0].length;
        int cnt=0;
        boolean[][] vis = new boolean[n][m];
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                vis[i][j]=false;
            }
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!vis[i][j] && grid[i][j]=='1') {
                    dfs(new Pair(i, j), n, m, grid, vis);
                    cnt++;
                }
            }
        }
        return cnt;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int rows = scanner.nextInt();
        int columns = scanner.nextInt();
        if(rows==0 || columns==0) {
            System.out.println(0);
            scanner.close();
            return;
        }
        char[][] grid = new char[rows][columns];

        for (int i = 0; i < rows; ++i) {
            String s = scanner.next();
            for (int j = 0; j < columns; ++j) {
                grid[i][j] = s.charAt(j);
            }
        }
        scanner.close();
        int result = new NumberOfIslands().numIslands(grid);
        System.out.println(result);
    }
}