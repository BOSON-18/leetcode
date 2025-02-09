class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        int n = nums.size();
        int mini = 1e9;
        sort(begin(nums), end(nums));

        for (int k = 0; k <= n - 3; k++) {
            int i = k + 1, j = n - 1;

            while (i < j) {
                int sum = nums[k] + nums[j] + nums[i];

                if (abs(target - sum) < abs(target - mini))
                    mini = sum;

                if (sum < target)
                    i++;
                else
                    j--;
            }
        }

        return mini;
    }
};