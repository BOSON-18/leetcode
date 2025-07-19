class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {

        sort(begin(folder), end(folder));
        vector<string> ans;
        ans.push_back(folder[0]);
        for(int i=1;i<folder.size();i++){
            string curr = folder[i];
            string last = ans.back();

            last+='/';

            if(curr.find(last)!=0) ans.push_back(curr);
        }
        return ans;
    }
};