class Solution {
public:
    int n;
    bool rec(int index, int sum, int target, vector<int>& nums) {

        if (sum == target)
            return true;
        if (index == n)
            return false;
        if (sum > target)
            return false;

        bool take = rec(index + 1, sum + nums[index], target, nums);
        bool notTake = rec(index + 1, sum, target, nums);

        return take | notTake;
    }
    bool memo(vector<int>& nums, int idx, int sum, int target,
              vector<vector<int>>& dp) {
        if (idx >= nums.size()) {
            return false;
        }
        if (sum > target) {
            return false;
        }
        if (sum == target) {
            return true;
        }
        if (dp[idx][sum] != -1) {
            return dp[idx][sum];
        }

        // Rec
        bool include = memo(nums, idx + 1, sum + nums[idx], target, dp);
        bool exclude = memo(nums, idx + 1, sum, target, dp);

        return dp[idx][sum] = include | exclude;
    }

    bool tabu(vector<int>& nums, int index, int sum, int target,
              vector<vector<int>>& dp) {

        for (int i = 0; i <= n; i++)
            dp[i][target] = 1;

        for (int index = n - 1; index >= 0; index--) {
            for (sum = target - 1; sum >= 0; sum--) {
                bool take = false;
                if (sum + nums[index] <= target) {
                    take = dp[index + 1][sum + nums[index]];
                }
                bool notTake = dp[index + 1][sum];

                dp[index][sum] = take | notTake;
            }
        }
        return dp[0][0];
    }

    bool canPartition(vector<int>& nums) {
        int target = 0;

        for (int i : nums) {
            target += i;
        }

        if (target % 2 != 0)
            return false;

        target /= 2;
        n = nums.size();

        vector<vector<int>> dp(n+1, vector<int>(target + 1, 0));

        //    return rec(0,0,target,nums);
        // return memo(nums, 0, 0, target, dp);
           return tabu(nums,0,0,target,dp);
    }
};