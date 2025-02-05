class Solution {
    void dfs(int row, int col, vector<vector<char>>& grid, vector<pair<int, int>>& temp, vector<vector<int>>& vis, int nrow, int ncol){
        int m = grid.size();
        int n = grid[0].size();
        vis[row][col]=1;
        temp.push_back({row-nrow, col-ncol});
        
        int crow[] = {-1, 0, 1, 0};
        int ccol[] = {0, -1, 0, 1};
        for(int i=0;i<4;i++){
            int trow = row + crow[i];
            int tcol = col + ccol[i];
            if(trow>=0 && trow<m && tcol>=0 && tcol<n && !vis[trow][tcol] && grid[trow][tcol]=='1'){
                dfs(trow, tcol, grid, temp, vis, nrow, ncol);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<pair<int, int>>> st;
        vector<vector<int>> vis(m, vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    vector<pair<int, int>> temp;
                    dfs(i, j, grid, temp, vis, i, j);
                    st.push_back(temp);
                }
            }
        }
        return st.size();
    }
};