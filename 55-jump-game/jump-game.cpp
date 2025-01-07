class Solution {
public:
    int n;

    bool memo(vector<int>& nums, int index, vector<int>& dp) {

        if (index == n - 1)
            return true;

        if (dp[index] != -1)
            return dp[index];

        if (nums[index] == 0)
            return dp[index] = false;

        for (int i = 1; i <= nums[index]; i++) {
            if (memo(nums, index + i, dp))
                return dp[index] = true;
        }
        return dp[index] = false;
    }

    bool optimise(vector<int>& nums) {
        int maxIndex = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (maxIndex < i)
                return false;
            maxIndex = max(maxIndex,i+ nums[i]);
        }
        return true;
    }
    bool canJump(vector<int>& nums) {

        return optimise(nums);

        n = nums.size();
        // vector<int> dp(n, -1);
        vector<bool> dp(n, 0);
        dp[n - 1] = 1;

        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j <= nums[i]; j++) {
                if (dp[i + j]) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[0];
        // return memo(nums, 0, dp);
    }
};