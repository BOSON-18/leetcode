class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        // nums[i]+nums[j]+nums[k] == 0
        //  i!=j!=k

        vector<vector<int>> ans;
        // No dupluicates must be there one more constraint

        // Brute Force
        //  Three Loops TC (O(N^3))

        // How to know duplicate will create or not
        // ->Sort equal will come together

        sort(begin(nums), end(nums));
        int n = nums.size();
        for (int i = 0; i < n - 2; i++) {
            if (i != 0 && nums[i - 1] == nums[i])
                continue;

            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum > 0)
                    k--;
                if (sum < 0)
                    j++;
                if (sum == 0){
                    ans.push_back({nums[i], nums[j], nums[k]});
                j++;
                k--;

                while (j < k && nums[j] == nums[j - 1])
                    j++;
                while (j < k && nums[k] == nums[k + 1])
                    k--;
                    }
            }
        }

        return ans;
    }
};