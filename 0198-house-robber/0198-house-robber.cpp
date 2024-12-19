class Solution {
public:
    int recursion(vector<int>& nums, int index, vector<int>& dp) {
        if (index < 0)
            return 0;
        if (dp[index] != -1)
            return dp[index];
        // pick not pick

        int pick = nums[index] + recursion(nums, index - 2, dp);
        int notPick = 0 + recursion(nums, index - 1, dp);

        return dp[index] = max(pick, notPick);
    }
    int rob(vector<int>& nums) {

        // vector<int> dp(nums.size(),-1);
    int n=nums.size();
    vector<int>dp(n,0);

       dp[0] = nums[0];
    
    // Iterate through the elements of the numsay
    for (int i = 1; i < n; i++) {
        // Calculate the maximum value by either picking the current element
        // or not picking it (i.e., taking the maximum of dp[i-2] + nums[i] and dp[i-1])
        int pick = nums[i];
        if (i > 1)
            pick += dp[i - 2];
        int nonPick = dp[i - 1];
        
        // Store the maximum value in the dp numsay
        dp[i] = max(pick, nonPick);
    }
    
    // The last element of the dp numsay will contain the maximum sum
    return dp[n - 1];
    }
};