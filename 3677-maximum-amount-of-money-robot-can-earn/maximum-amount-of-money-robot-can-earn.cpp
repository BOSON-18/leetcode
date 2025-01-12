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
        memset(dp,-1,sizeof(dp));
        return memo(coins, m - 1, n - 1, 2);
    }
};