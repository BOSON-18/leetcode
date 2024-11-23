class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> prev(amount + 1, 0), curr(amount + 1, 0);

        // Base case: If target = 0, there's one way (choose no coins)
        // prev[0] = 1;

        // Initialize for the first coin
        for (int target = 0; target <= amount; target++) {
            if (target % coins[0] == 0) prev[target] = 1;
        }

        for (int i = 1; i < n; i++) {
            for (int target = 0; target <= amount; target++) {
                long int notTake = prev[target];
                long int take = 0;
                if (coins[i] <= target) take = curr[target - coins[i]];
                curr[target] = take + notTake;
            }
            prev = curr;
        }

        return prev[amount];
    }
};
