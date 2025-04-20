class Solution {
    void dfs(int r, int c, int prevHeight, vector<vector<int>>& vis, vector<vector<int>>& heights){
        if(r < 0 || c < 0 || r == heights.size() || c == heights[0].size() || vis[r][c] || heights[r][c] < prevHeight){
            return ;
        }

        vis[r][c] = 1;

        dfs(r + 1, c, heights[r][c], vis, heights);
        dfs(r - 1, c, heights[r][c], vis, heights);
        dfs(r, c + 1, heights[r][c], vis, heights);
        dfs(r, c - 1, heights[r][c], vis, heights);
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> pac(m, vector<int>(n, 0));
        vector<vector<int>> atl(m, vector<int>(n, 0));

        for(int i=0;i<n;i++){
            dfs(0, i, heights[0][i], pac, heights);
            dfs(m-1, i, heights[m-1][i], atl, heights);
        }

        for(int i=0;i<m;i++){
            dfs(i, 0, heights[i][0], pac, heights);
            dfs(i, n-1, heights[i][n-1], atl, heights);
        }

        vector<vector<int>> res;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pac[i][j] && atl[i][j]){
                    res.push_back({i, j});
                }
            }
        }

        return res;
    }
};