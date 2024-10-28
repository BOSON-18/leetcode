class Solution {
public:
    void check(vector<long long>& arr, int& maxLength) {
        if (arr.size() < 2)
            return;

        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] != arr[i - 1] * arr[i - 1])
                return;
        }

        maxLength = max(maxLength, (int)arr.size());
    }

    int dfs(int index, int maxLength, vector<long long>& arr,
            vector<int>& nums) {
        // base case
        if (index >= nums.size())
            return maxLength;

        // take the curr element

        arr.push_back(nums[index]);
        check(arr, maxLength);
        maxLength = dfs(index + 1, maxLength, arr, nums);
        arr.pop_back();

        // Do not take the current element
        maxLength = dfs(index + 1, maxLength, arr, nums);

        return maxLength;
    }
    int longestSquareStreak(vector<int>& nums) {
        //     sort(nums.begin(),nums.end());
        //     vector<long long> arr;
        //    int maxi=-1;
        //    return  dfs(0,maxi,arr,nums);

        unordered_map<int, int> mpp;
        sort(nums.begin(), nums.end());
        int res = -1;
        for (int num : nums) {
            int root = sqrt(num);
            if (root * root == num && mpp[root] > 0) {
                mpp[num] = mpp[root] + 1;
                res = max(res, mpp[num]);
            } else {
                mpp[num] = 1;
            }
        }
        return res;
    }
};