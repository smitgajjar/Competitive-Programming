class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int r = obstacleGrid.size(), c = obstacleGrid[0].size();
        long long dp[r][c];
        
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                dp[i][j]=0;
                if(!obstacleGrid[i][j]) {
                    
                    if(i==0 and j!=0) {
                        dp[i][j] = dp[i][j-1];
                    }
                    else if(j==0 and i!=0) {
                        dp[i][j] = dp[i-1][j];
                    }
                    else if (i!=0 and j!=0) {
                        dp[i][j] = (long long)dp[i-1][j] + dp[i][j-1];
                    }
                    else if(i==0 and j==0) {
                        dp[i][j]=1;
                    }
                }
            }
        }
        return dp[r-1][c-1];
    }
};