class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        // Previous row initialized to the first row of the matrix
        vector<int> prev = matrix[0];

        for (int i = 1; i < n; i++) {
            vector<int> curr(m);
            for (int j = 0; j < m; j++) {
                int up = matrix[i][j] + prev[j];
                int left = j - 1 >= 0 ? matrix[i][j] + prev[j - 1] : INT_MAX;
                int right = j + 1 < m ? matrix[i][j] + prev[j + 1] : INT_MAX;

                curr[j] = min({up, left, right});
            }
            prev = curr; // Update prev to current row
        }

        // Compute the minimum falling path sum from the last row
        int mini = INT_MAX;
        for (int j = 0; j < m; j++) {
            mini = min(mini, prev[j]);
        }

        return mini;
    }
};
