class Solution {
public:
    bool isVowel(char& ch) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
            return true;
        return false;
    }
    bool isValid(string word) {
        if(word.size()<3) return false;
        int vowel = 0, cons = 0;

        for (char& ch : word) {
            if (isalnum(ch)) {
                if (isVowel(ch)) {
                    vowel++;
                } else if(!isdigit(ch)) {
                    cons++;
                }
            } else {
                return false;
            }
        }
        if (vowel > 0 && cons > 0)
            return true;
        return false;
    }
};