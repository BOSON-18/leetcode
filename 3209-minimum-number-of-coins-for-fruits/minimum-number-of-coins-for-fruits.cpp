class Solution {
public:
    int minimumCoins(vector<int>& prices) {

        int n = prices.size();

        vector<int> dp(n + 1, -1);

        dp[n] = 0;
        dp[n - 1] = prices[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            int minCoins = INT_MAX;
            for (int j = i + 1; j <= min(2*i + 2, n); j++) {
                minCoins = min(minCoins, dp[j]);
            }
            dp[i] = prices[i] + minCoins;
        }

        return dp[0];
    }
};