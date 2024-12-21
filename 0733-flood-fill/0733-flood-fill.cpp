class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int n = image.size(), m = image[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int,int>> q;

        int original = image[sr][sc];
        vector<int> dRow = {0, 1, 0, -1};
        vector<int> dCol = {1, 0, -1, 0};

        q.push({sr, sc});
        image[sr][sc] = color;
        vis[sr][sc] = 1;

        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nRow = row + dRow[i];
                int nCol = col + dCol[i];

                if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m &&
                        vis[nRow][nCol] == 0 && image[nRow][nCol] ==original) {
                    q.push({nRow, nCol});
                    vis[nRow][nCol] = 1;
                    image[nRow][nCol]=color;
                }
            }
        }

        return image;
    }
};