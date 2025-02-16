class Solution {
public:
   bool hasSpecialSubstring(string s, int k) {
    int count = 1;
    if(s.size() == 1 && k == 1) return true;
    for(int i = 1; i < s.size(); i++, count++){
        if(s[i] != s[i-1] && count == k) return true;
        if(s[i] != s[i-1]) count = 0;
    }
    return (count == k);

    }
};