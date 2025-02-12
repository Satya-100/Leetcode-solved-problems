class Solution {
    int f(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(row==0 && col==0)    return grid[0][0];
        if(row<0 || col<0)  return 1e9;
        if(dp[row][col]!=-1)    return dp[row][col];
        int left = grid[row][col] + f(row, col-1, grid, dp);
        int up = grid[row][col] + f(row-1, col, grid, dp);
        return dp[row][col] = min(left, up);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0)    dp[i][j]=grid[i][j];
                else{
                    int up=grid[i][j];
                    if(i>0) up+=dp[i-1][j];
                    else    up+=1e9;
                    int left=grid[i][j];
                    if(j>0) left+=dp[i][j-1];
                    else    left+=1e9;
                    dp[i][j]=min(up, left);
                }
            }
        }

        return dp[m-1][n-1];
    }
};