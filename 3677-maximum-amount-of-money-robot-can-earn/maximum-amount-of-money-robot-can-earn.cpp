class Solution {
public:
    int m, n;
int dp[501][501][3];
    int memo(vector<vector<int>>& coins, int row, int col, int defend) {

        if (row == 0 && col == 0) {
            if (defend > 0 && coins[row][col] < 0)
                return 0;
            else
                return coins[row][col];
        }


        if (row < 0 || col < 0)
            return INT_MIN;
        if(dp[row][col][defend]!=-1) return dp[row][col][defend];

        int take = INT_MIN, notTake = INT_MIN;

        take = coins[row][col] + max(memo(coins, row - 1, col, defend),
                                     memo(coins, row, col - 1, defend));
        if (defend > 0 && coins[row][col] < 0) {
            notTake = max(memo(coins, row - 1, col, defend - 1),
                          memo(coins, row, col - 1, defend - 1));
        }

        return dp[row][col][defend]=max(take, notTake) ;
    }
    int maximumAmount(vector<vector<int>>& coins) {

        m = coins.size(), n = coins[0].size();
        // memset(dp,-1,sizeof(dp));
        // return memo(coins, m - 1, n - 1, 2);

        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(3,INT_MIN)));


        //base case
        dp[0][0][0]=coins[0][0];
          if (coins[0][0]<0) {
            //defend kr lenge
            dp[0][0][1]=0; 
            dp[0][0][2]=0;
        } else {
            dp[0][0][1]=dp[0][0][2]=coins[0][0];
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<3;k++){
                    if(i==0 && j==0) continue;

                    if(i>0){
                        dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+coins[i][j]);
                        if(coins[i][j]<0 && k>0){
                            dp[i][j][k]= max(dp[i][j][k],dp[i-1][j][k-1]);
                        }
                    }

                    if(j>0){
                        dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k]+coins[i][j]);
                        if(coins[i][j]<0 && k>0){
                            dp[i][j][k]= max(dp[i][j][k],dp[i][j-1][k-1]);
                        }
                    }
                }
            }
        }

        return max({dp[m-1][n-1][0],dp[m-1][n-1][1],dp[m-1][n-1][2]});
    }
};