class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int tuples=0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                mpp[nums[i] * nums[j]]++;
            }
        }

        for(auto it:mpp){
            int product=it.first;
            int frequency=it.second;

            tuples += (frequency*(frequency-1))/2; // nC2 wala formula

        }

        return tuples*8;
    }
};