class Solution {
public:
void markRow(vector<vector<int>> & matrix,int row){
    for(int i=0;i<matrix[0].size();i++){
        if(matrix[row][i]!=0){
            matrix[row][i]=-6969;
        }
    }
}

void markCol(vector<vector<int>> & matrix,int col){
    for(int i=0;i<matrix.size();i++){
        if(matrix[i][col]!=0){
            matrix[i][col]=-6969;
        }
    }
}
   void setZeroes(vector<vector<int>>& matrix) {
    int col0 = 1, rows = matrix.size(), cols = matrix[0].size();

    for (int i = 0; i < rows; i++) {
        if (matrix[i][0] == 0) col0 = 0;
        for (int j = 1; j < cols; j++)
            if (matrix[i][j] == 0)
                matrix[i][0] = matrix[0][j] = 0;
    }

    for (int i = rows - 1; i >= 0; i--) {
        for (int j = cols - 1; j >= 1; j--)
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        if (col0 == 0) matrix[i][0] = 0;
    }
}
};