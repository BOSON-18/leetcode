class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {

        int n = nums.size();

        sort(begin(nums), end(nums));
        int mini = nums[0][0], maxi = nums[0][1];
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i][0] <= maxi) {
                // Overlap
                

                maxi=max(maxi,nums[i][1]);
            } else {
                ans += (maxi - mini + 1);
                mini = nums[i][0];
                maxi = nums[i][1];
            }
        }
        ans += (maxi - mini + 1);
        return ans;
    }
};