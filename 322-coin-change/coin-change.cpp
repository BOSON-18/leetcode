class Solution {
public:
    int f(vector<int>& arr, int amount, int index, vector<vector<int>>& memo) {
        // A recursive function which will return minimum coins combination
        // base case
        if (amount == 0)
            return 0;
        if (index == arr.size())
            return 1e9; // as we will comapre both sides of tree and will take
                        // min of them
        if (memo[index][amount] != -1)
            return memo[index][amount];
        // if(amount<0) return 1e9;

        // take or not take
        int take = 1e9; // as we are going to use min
        if (amount >= arr[index])
            take = 1 +
                   f(arr, amount - arr[index], index, memo); // reusing the coin

        // not take
        int notTake = f(arr, amount, index + 1, memo);

        return memo[index][amount] = min(take, notTake);
    }
      int tab(vector<int>& coins, int amount) {
        int n = coins.size();
        
        // Create a DP table, initialize to a large value (1e9 for infinity)
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 1e9));
        
        // Base case: If amount is 0, we need 0 coins
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }
        
        // Fill the table
        for (int index = n - 1; index >= 0; index--) {
            for (int amt = 1; amt <= amount; amt++) {
                // Not take the current coin
                int notTake = dp[index + 1][amt];
                
                // Take the current coin (if possible)
                int take = 1e9;
                if (amt >= coins[index]) {
                    take = 1 + dp[index][amt - coins[index]];
                }
                
                // Take the minimum of both
                dp[index][amt] = min(take, notTake);
            }
        }
        
        // The answer is in dp[0][amount]
        return dp[0][amount] >= 1e9 ? -1 : dp[0][amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        // coins hai 1,2,5 infinite supply
        // inke combination se amount bnao

        // Can we apply greedy????
        // Lets see if we want to minimise the no of coins used so will use
        // largest denomination first 5+5=10 now 10+5 =15 -- 10+2=12 -- 10+1= 11
        // yes so will need 2 5 and 1 1 coin toal no of coins = 3

        // Now take an example
        // 1,6,7,9,11 amount =13
        // Greedy approach will say
        // 1 11 coin and 2 1 coins total 3
        // But if u observe now we can also make the toal by using
        // 1 6 and 1 7 coin total coins= 2
        // Hence Greedy failed
        // So now greedy is failed so we have to try out all the possible
        // combinations

        // Call a recursive function

        // vector<vector<int>> memo(coins.size(), vector<int>(amount + 1, -1));

        // int ans = f(coins, amount, 0, memo);

        // return ans == 1e9 ? -1 : ans;
        return tab(coins,amount);
    }
};