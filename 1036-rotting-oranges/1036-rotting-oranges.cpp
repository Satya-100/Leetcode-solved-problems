class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int total = 0;
        int cnt = 0;
        int min = 0;

        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0)
                    total++;
                if (grid[i][j] == 2)
                    q.push({i, j});
            }
        }

        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {1, -1, 0, 0};

        while (!q.empty()) {
            int k = q.size();
            cnt += k;
            while (k--) {
                auto it = q.front();
                q.pop();
                int x = it.first;
                int y = it.second;

                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if(nx<0 || ny<0 || ny>=n || nx>=m || grid[nx][ny]!=1)   continue;
                    grid[nx][ny] = 2;
                    q.push({nx, ny});
                }
            }
            if (!q.empty())
                min++;
        }
        return total == cnt ? min : -1;
    }
};