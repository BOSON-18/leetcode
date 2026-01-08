class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<vector<string>> ans;
        unordered_map<string,vector<string>> mpp;
        for(string s:strs){
            // sort(s.begin(),s.end());
            string st = s;
            sort(st.begin(),st.end());
            mpp[st].push_back(s);
        }

        for(auto it: mpp){
            ans.push_back(it.second);
        }

        return ans;
        
    }
};