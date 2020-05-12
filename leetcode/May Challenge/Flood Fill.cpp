class Solution {
public:
    bool isValid(vector<vector<int>>& image, int x, int y, int color, int n, int m, vector<vector<bool>> vis) {
        if(x>-1 and x<n and y>-1 and y<m and image[x][y]==color and !vis[x][y])
            return true;
        return false;
    }
    void fill(vector<vector<int>>& image, int x, int y, int newColor, int n, int m, vector<vector<bool>> vis) {
        int curr_color=image[x][y];
        image[x][y]=newColor;
        vis[x][y]=true;
        cout<<x<<' '<<y<<endl;
        if(isValid(image, x-1, y, curr_color, n, m, vis))
            fill(image, x-1, y, newColor, n, m, vis);
        if(isValid(image, x, y-1, curr_color, n, m, vis))
            fill(image, x, y-1, newColor, n, m, vis);
        if(isValid(image, x+1, y, curr_color, n, m, vis))
            fill(image, x+1, y, newColor, n, m, vis);
        if(isValid(image, x, y+1, curr_color, n, m, vis))
            fill(image, x, y+1, newColor, n, m, vis);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n=image.size(), m=image[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        fill(image, sr, sc, newColor, n, m, vis);
        return image;
    }
};