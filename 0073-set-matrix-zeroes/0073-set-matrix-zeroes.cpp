class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // Assume if 0 ise present at mat[1][1] then need to make row 1 and col
        // 1 fully 0

        // Brute Force
        // Make a list to store the index of the 0's in the matrix
        // After it based on the pair of index make changes in original array

        vector<pair<int, int>> zeroes;
        int n = matrix.size(), m = matrix[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0)
                    zeroes.push_back({i, j});
            }
        }
        unordered_set<int> Rst;
        unordered_set<int> Cst;

        for (auto it : zeroes) {
            int row = it.first;
            int col = it.second;

            if (Rst.find(row) == Rst.end()) {
                Rst.insert(row);
                for (int i = 0; i < m; i++) {
                    matrix[row][i] = 0;
                }
            }

            if (Cst.find(col) == Cst.end()) {
                Cst.insert(col);
                for (int i = 0; i < n; i++) {
                    matrix[i][col] = 0;
                }
            }
        }
    }
};