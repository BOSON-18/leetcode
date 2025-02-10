class Solution {
public:
    int n;
    vector<vector<long long>> dp;

    long long memo(vector<int>& nums, int index, bool isEven) {
        if (index == n) return 0; 
        
        if (dp[index][isEven] != -1) return dp[index][isEven]; 

        long long take = (isEven ? nums[index] : -nums[index]) + memo(nums, index + 1, !isEven);
        long long notTake = memo(nums, index + 1, isEven);

        return dp[index][isEven] = max(take, notTake);
    }

    long long maxAlternatingSum(vector<int>& nums) {
        n = nums.size();
        dp.assign(n, vector<long long>(2, -1)); // Initialize DP array with -1
        return memo(nums, 0, true);
    }
};
