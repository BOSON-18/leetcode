class Solution {
public:
    bool canConstruct(string s, int k) {

        if(s.size()<k) return false;

        unordered_map<char,int> mpp;

        for(char& ch:s) mpp[ch]++;
    int count=0;
       for (auto it = mpp.begin(); it != mpp.end(); ++it) {
        cout << it->first << ": " << it->second << endl;
        if(it->second%2==1) count++;
    }
        return count>k ? false:true;
    }
};