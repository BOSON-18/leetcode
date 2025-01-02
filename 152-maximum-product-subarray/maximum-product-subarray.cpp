class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int maxProduct = nums[0];
        int minProduct = nums[0];
        int result = nums[0];

        for (int i = 1; i < n; ++i) {
            // If the current number is negative, swap maxProduct and minProduct
            if (nums[i] < 0) {
                swap(maxProduct, minProduct);
            }

            // Update maxProduct and minProduct
            maxProduct = max(nums[i], maxProduct * nums[i]);
            minProduct = min(nums[i], minProduct * nums[i]);

            // Update the result
            result = max(result, maxProduct);
        }

        return result;
    }
};
