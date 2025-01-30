class Solution {
    void dfs(vector<vector<int>>& image, int i, int j, int row, int col,int color, int oldColor){
        if(i<0 || i>=row || j<0 || j>=col || image[i][j]!=oldColor)   return ;

        image[i][j]=color;

        dfs(image, i+1, j, row, col, color, oldColor);
        dfs(image, i-1, j, row, col, color, oldColor);
        dfs(image, i, j+1, row, col, color, oldColor);
        dfs(image, i, j-1, row, col, color, oldColor);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color)    return image;
        int r=image.size();
        int c=image[0].size();
        int oldColor = image[sr][sc];
        dfs(image, sr, sc, r, c, color, oldColor);
        return image;
    }
};