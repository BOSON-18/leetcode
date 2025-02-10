class Solution {
public:
    string clearDigits(string s) {

        int leftIndex=0;

        string ans="";

        for(int i=0;i<s.size();i++){
            if(isalpha(s[i])){
                leftIndex=i;
                ans.push_back(s[i]);
            }
            else if(isdigit(s[i])){
                ans.pop_back();
                // if(i<s.size()-1)
                leftIndex=max(leftIndex-1,i+1);

            }
        }
        return ans;
    }
};