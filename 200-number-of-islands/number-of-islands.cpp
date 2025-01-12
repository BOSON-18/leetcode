class Solution {
public:
    int m, n;
    int dRow[4] = {-1, 0, 1, 0};
    int dCol[4] = {0, -1, 0, 1};

    void dfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int row,
             int col) {

        vis[row][col] = 1;

        for (int i = 0; i < 4; i++) {
            int nRow = row + dRow[i];
            int nCol = col + dCol[i];
            if (nRow >= 0 && nCol >= 0 && nRow < m && nCol < n &&
                !vis[nRow][nCol] && grid[nRow][nCol] == '1')
                dfs(grid, vis, nRow, nCol);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && vis[i][j] == 0) {
                    dfs(grid, vis, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};