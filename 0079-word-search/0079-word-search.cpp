class Solution {
    bool dfs(int r, int c, int i, vector<vector<int>>& vis, string word, vector<vector<char>>& board){
        if(i == word.size())    return true;
        if(r<0 || c<0 || r==vis.size() || c == vis[0].size() || vis[r][c]==1)   return false;
        if(word[i]!=board[r][c])    return false;

        vis[r][c] = 1;
        bool res = false;

        int x[4] = {0, 0, 1, -1};
        int y[4] = {1, -1, 0, 0};

        for(int d=0;d<4;d++){
            res |= dfs(r+x[d], c+y[d], i+1, vis, word, board);
        }

        vis[r][c] = -1;
        return res;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m, vector<int>(n, -1));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dfs(i, j, 0, vis, word, board))   return true;
            }
        }

        return false;
    }
};