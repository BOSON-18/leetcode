class Solution {
public:
    int n, m, size;
    vector<int> dRow = {0, -1, 0, 1};
    vector<int> dCol = {1, 0, -1, 0};

    bool f(vector<vector<char>>& matrix, string& word, int index, int row, int col, vector<vector<bool>>& visited) {
        // If we have matched all characters
        if (index == size)
            return true;

        // Mark the current cell as visited
        visited[row][col] = true;

        // Explore all 4 directions
        for (int i = 0; i < 4; i++) {
            int nRow = row + dRow[i];
            int nCol = col + dCol[i];

            // Check bounds, character match, and if the cell is not visited
            if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m &&
                !visited[nRow][nCol] && matrix[nRow][nCol] == word[index]) {
                if (f(matrix, word, index + 1, nRow, nCol, visited))
                    return true;
            }
        }

        // Backtrack: unmark the current cell
        visited[row][col] = false;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        size = word.size();

        // Create a visited array
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    // Start DFS from this cell
                    if (f(board, word, 1, i, j, visited))
                        return true;
                }
            }
        }
        return false;
    }
};
