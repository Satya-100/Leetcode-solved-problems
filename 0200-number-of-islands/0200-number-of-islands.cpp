class Solution {
    void traverse(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid){
        int m=grid.size();
        int n=grid[0].size();
        if(row<0 || row>=m || col<0 || col>=n)  return ;
        if(grid[row][col]!='1') return ;
        if(vis[row][col])   return ;
        vis[row][col] = 1;

        traverse(row, col+1, vis, grid);
        traverse(row, col-1, vis, grid);
        traverse(row+1, col, vis, grid);
        traverse(row-1, col, vis, grid);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int island=0;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    traverse(i, j, vis, grid);
                    island++;
                }
            }
        }
        return island;
    }
};