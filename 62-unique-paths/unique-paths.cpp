class Solution {
public:
int t[101][101];
int memo(int m,int n,int row,int col){
    if(t[row][col]!=-1) return t[row][col];
    if(row == m-1 && col==n-1) return t[row][col]=1;

    int down=0,right=0;

    if(row+1<m) down= memo(m,n,row+1,col);
    if(col+1 <n ) right = memo(m,n,row,col+1);

    return t[row][col]= down+right;
}
    int uniquePaths(int m, int n) {
        // Only down and right 
        // i +1 || j+1  at a time bound check krna
        // memset(t,-1,sizeof(t));

        vector<vector<int>> dp(m,vector<int>(n,0));
        dp[m-1][n-1]=1;

        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i+1<m) dp[i][j]+=dp[i+1][j];
                if(j+1<n) dp[i][j]+=dp[i][j+1];
            }
        }
        return dp[0][0];
        // return memo(m,n,0,0);
    }
};