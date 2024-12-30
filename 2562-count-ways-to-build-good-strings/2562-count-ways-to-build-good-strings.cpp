class Solution {
public:
    int Low, High, Zero, One;
    const int MOD = 1e9 + 7;

    // Memoization map to store results for each string length
    unordered_map<int, int> memo;

    int recu(int length) {
        // If the current length exceeds the maximum allowed length, return 0
        if (length > High) return 0;

        // If the result for this length is already computed, return it
        if (memo.find(length) != memo.end()) return memo[length];

        // Check if the current length is within the valid range [Low, High]
        int count = (length >= Low) ? 1 : 0;

        // Add valid strings formed by appending Zero '0's
        count = (count + recu(length + Zero)) % MOD;

        // Add valid strings formed by appending One '1's
        count = (count + recu(length + One)) % MOD;

        // Store the result in the memoization map
        return memo[length] = count;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        Low = low;
        High = high;
        Zero = zero;
        One = one;

        // Start recursion with an initial length of 0
        return recu(0);
    }
};
