class Solution {
public:
    static bool comparator(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];  // Sort by the second element
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), comparator);
        
        int count = 0, lastEnd = INT_MIN;
        for (auto& pair : pairs) {
            if (pair[0] > lastEnd) {
                count++;
                
                lastEnd = pair[1];
            }
        }
        return count;
    }
};
