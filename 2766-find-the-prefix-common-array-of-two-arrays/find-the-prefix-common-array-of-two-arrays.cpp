class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        // prefix array [i] == No of common numbers till index i
        int n = A.size();
        // brute force
        unordered_map<int, int> mpp;
        // will store max index in both of the array
        for (int i = 0; i < n; i++) {
            int element = A[i];
            mpp[element] = i;
        }

        for (int i = 0; i < n; i++) {
            int element = B[i];
            mpp[element] = max(i, mpp[element]);
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            int common = 0;
            for (auto it : mpp) {
                if (it.second <= i)
                    common++;
            }
            ans.push_back(common);
        }
        return ans;
    }
};