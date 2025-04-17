class Solution {
public:
    int countPairs(vector<int>& nums, int k) {

        int n = nums.size();
        unordered_map<int, vector<int>> mpp;
        int pairs = 0;
        for (int i = 0; i < n; i++) {
            if (mpp.find(nums[i]) != mpp.end()) {
                for (int it : mpp[nums[i]]) {
                    if ((it * i) % k == 0 )
                        pairs++;
                }
            }
            mpp[nums[i]].push_back(i);
        }
        return pairs;
    }

};