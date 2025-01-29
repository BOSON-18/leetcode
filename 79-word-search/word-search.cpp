class Solution {
public:
    int dRow[4] = {0, -1, 0, 1};
    int dCol[4] = {1, 0, -1, 0};
    int n, m, size;

    bool solve(vector<vector<char>>& board, string& word, int index, int row,
               int col, vector<vector<bool>>& vis) {
        if (index == size)
            return true;

        vis[row][col] = true;

        for (int i = 0; i < 4; i++) {
            int nRow = row + dRow[i];
            int nCol = col + dCol[i];

            if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m &&
                !vis[nRow][nCol] && board[nRow][nCol] == word[index]) {
                if (solve(board, word, index + 1, nRow, nCol, vis))
                    return true;
            }
        }
        vis[row][col] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size(), m = board[0].size();
        size = word.size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    if (solve(board, word, 1, i, j, vis))
                        return true;
                }
            }
        }
        return false;
    }
};