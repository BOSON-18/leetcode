class Solution {
public:
    bool check(string& one, string& two) {
        int i = 0;
        int n = one.size(), m = two.size();
        if (n < m)
            return false;

        while (i < m) {
            if (one[i] != two[i])
                return false;
            i++;
        }
        return true;
    }
    int prefixCount(vector<string>& words, string pref) {

        int count = 0;
        int n = words.size();
        for (int i = 0; i < n; i++) {
            if (check(words[i], pref))
                count++;
        }

        return count;
    }
};