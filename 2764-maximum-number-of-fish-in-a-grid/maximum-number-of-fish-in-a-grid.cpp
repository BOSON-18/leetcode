class Solution {
public:
    int n, m;
    int dRow[4] = {0, -1, 0, 1};
    int dCol[4] = {-1, 0, 1, 0};

    int dfs(int row, int col, vector<vector<int>>& grid,
            vector<vector<bool>>& vis) {

      int fish=grid[row][col];
        vis[row][col] = 1;

        for (int i = 0; i < 4; i++) {
            int nRow = row + dRow[i];
            int nCol = col + dCol[i];

            if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m &&
                grid[nRow][nCol] > 0 && vis[nRow][nCol] == 0) {
                fish +=dfs(nRow, nCol, grid, vis);
            }
        }
        return fish;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int maxFish = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] > 0 && !vis[i][j]) {
                    maxFish = max(maxFish, dfs(i, j, grid, vis));
                }
            }
        }
        return maxFish;
    }
};