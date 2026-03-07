class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n == 0) return 0;

        unordered_map<char,int> freq;
        int l = 0, r = 0, maxi = 0;

        while (r < n) {
            freq[s[r]]++;

            // If duplicate exists, shrink window
            while (freq[s[r]] > 1) {
                freq[s[l]]--;
                l++;
            }

            maxi = max(maxi, r - l + 1);
            r++;
        }

        return maxi;
    }
};
