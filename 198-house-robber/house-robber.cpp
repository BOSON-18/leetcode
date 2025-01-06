class Solution {
public:
    int memo(vector<int>& arr, int index, vector<int>& dp) {
        if (index >= arr.size())
            return 0;
        if (dp[index] != -1)
            return dp[index];

        // take or not take

        int take = arr[index] + memo(arr, index + 2, dp);
        int notTake = 0 + memo(arr, index + 1, dp);

        return dp[index] = max(take, notTake);
    }
    int rob(vector<int>& nums) {
        // vector<int> dp(nums.size(),-1);
        vector<int> dp(nums.size() + 1, 0);
        // return memo(nums,0,dp);
        int n = nums.size();
        dp[n] = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            int take = nums[i] ;
            if(i<n-1)
            take+= dp[i + 2];
            int notTake = dp[i + 1];

            dp[i] = max(take, notTake);
        }
        return dp[0];
    }
};