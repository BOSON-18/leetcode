class Solution {
    unordered_set<string> st;
    int pLength = 3;
    unordered_map<string, int> mpp;

public:
    int countPalindromicSubsequence(string s) {
        // Need all unique palindromic subsequence of length 3
        // We just need to check if the last and first char is same or not

        // string str = "";
        int n = s.size();
        // f is a recursive function that will return the unique no of
        // palindromic subsequene   of        length 3
        // return f(s, str, n - 1);
        unordered_set<char> letters;
        for (char ch : s) {
            letters.insert(ch);
        }

        int result = 0;

        for (char ch : letters) {
            int leftMost = -1, rightMost = -1;

            for (int i = 0; i < n; i++) {
                if (s[i] == ch) {
                    if (leftMost == -1)
                        leftMost = i;

                    rightMost = i;
                }
            }
            unordered_set<char> st;
            for (int i = leftMost + 1; i < rightMost; i++) {
                st.insert(s[i]);
            }

            result += st.size();
        }
        return result;
    }
};