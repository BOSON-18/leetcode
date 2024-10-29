class Solution {
public:

int m;
int n;
    int DFS(int row, int col, vector<vector<int>>& grid,vector<vector<int>>& t) {
      vector<int> directions = {-1, 0, 1};
        int moves = 0;
    if(t[row][col]!=-1){
        return t[row][col];
    }
        for (int dir : directions) {
            int newRow = row + dir;
            int newCol = col + 1;

            if (newRow >= 0 && newRow < m && newCol >= 0 &&
                newCol < n &&
                grid[newRow][newCol] > grid[row][col]) {
                moves = max(moves, 1 + DFS(newRow, newCol, grid,t));
            }
        }

        return t[row][col]=moves;
    }
    int maxMoves(vector<vector<int>>& grid) {

       m = grid.size();
       n = grid[0].size();

       vector<vector<int>> t(m,vector<int>(n,-1));

        int result = 0;

        for (int row = 0; row < m; row++) {
            result = max(result, DFS(row, 0, grid,t));
        }

        return result;
    }
};