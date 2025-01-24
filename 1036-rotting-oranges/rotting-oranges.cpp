class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // bfs
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<pair<int, int>, int>> q;
        int dRow[4] = {1, 0, -1, 0};
        int dCol[4] = {0, -1, 0, 1};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                }
            }
        }

        int time = 0;
        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            q.pop();
            time = max(time, t);

            for (int i = 0; i < 4; i++) {
                int nRow = row + dRow[i];
                int nCol = col + dCol[i];

                if (nRow >=0 && nRow <m && nCol >= 0 && nCol < n &&
                    vis[nRow][nCol] != 2 && grid[nRow][nCol] == 1) {
                    q.push({{nRow, nCol}, t + 1});
                    vis[nRow][nCol] = 2;
                }
            }
        }

        for (int i =0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (vis[i][j] != 2 && grid[i][j] == 1)
                    return -1;
            }
        }

        return time;
    }
};