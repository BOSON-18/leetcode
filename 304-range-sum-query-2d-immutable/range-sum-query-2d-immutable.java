class NumMatrix {

    private int [][] prefix;

    public NumMatrix(int[][] matrix) {

        int m=matrix.length;
        int n=matrix[0].length;

      prefix = new int[m+1][n+1];

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){

                prefix[i][j]= matrix[i-1][j-1]+ prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1];
          }
        }


        
    }
    
    public int sumRegion(int row1, int col1, int row2, int col2) {

        int r1=row1+1,r2=row2+1,c1=col1+1,c2=col2+1;

        return prefix[r2][c2]-prefix[r2][col1]-prefix[row1][c2]+prefix[row1][col1];
        
    }
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */