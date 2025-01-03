class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;

        int n = matrix.size(), m = matrix[0].size();
        int firstRow = 0, lastRow = n - 1, firstCol = 0, lastCol = m - 1;

        while (firstRow <= lastRow && firstCol <= lastCol) {
            // Traverse from left to right
            for (int i = firstCol; i <= lastCol; i++) {
                ans.push_back(matrix[firstRow][i]);
            }
            firstRow++;

            // Traverse from top to bottom
            if (firstRow <= lastRow) {
                for (int i = firstRow; i <= lastRow; i++) {
                    ans.push_back(matrix[i][lastCol]);
                }
                lastCol--;
            }

            // Traverse from right to left
            if (firstRow <= lastRow) {
                for (int i = lastCol; i >= firstCol; i--) {
                    ans.push_back(matrix[lastRow][i]);
                }
                lastRow--;
            }

            // Traverse from bottom to top
            if (firstCol <= lastCol) {
                for (int i = lastRow; i >= firstRow; i--) {
                    ans.push_back(matrix[i][firstCol]);
                }
                firstCol++;
            }
        }

        return ans;
    }
};
