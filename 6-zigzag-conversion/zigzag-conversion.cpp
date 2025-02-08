class Solution {
public:
    string convert(string s, int numRows) {

        if (numRows == 1 || numRows >= s.size())
            return s;

      vector<string> str(min(numRows, int(s.length())));

        int currentRow = 0;
        bool goingDown = true;

        for (char& c : s) {
            str[currentRow] += c;

            currentRow += goingDown ? 1 : -1;
            if (currentRow == 0 || currentRow == numRows - 1) {
                goingDown = !goingDown;
            }

        }

        string result;

        for (auto it : str) {
            result += it;
        }

        return result;
    }
};