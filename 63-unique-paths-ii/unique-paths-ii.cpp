class Solution {
public:
int dp[101][101];
int memo(int m,int n,int row,int col,vector<vector<int>>& obstacleGrid){
    // if(t[row][col]!=-1) return t[row][col];
    if(row == m-1 && col==n-1) dp[row][col]= 1;
    if(obstacleGrid[row][col]==1) dp[row][col]= 0;
    if(dp[row][col]!=-1) return dp[row][col];
    int down=0,right=0;

    if(row+1<m) down= memo(m,n,row+1,col,obstacleGrid);
    if(col+1 <n ) right = memo(m,n,row,col+1,obstacleGrid);

    return dp[row][col]= down+right;
}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        memset(dp,-1,sizeof(dp));
        return memo(m,n,0,0,obstacleGrid);
        
    }
};