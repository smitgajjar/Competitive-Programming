class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size(), m=matrix[0].size(), ans=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(i==0 or j==0)
                {
                    ans+=matrix[i][j];
                }
                else if(matrix[i][j])
                {
                    int temp=min({matrix[i-1][j], matrix[i][j-1], matrix[i-1][j-1]})+1;
                    if(temp)
                    {
                        ans+=temp;
                        matrix[i][j]=temp;
                    }
                }
            }
        }
        return ans;
    }
};