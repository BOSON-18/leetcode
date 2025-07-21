class Solution {
public:
    string makeFancyString(string s) {
        int count =1;
        int i=1;
        int n= s.size();
        string ans="";
        ans.push_back(s[0]);

        while(i<n){
            if(s[i]==s[i-1]){
                count++;
            }else if(s[i]!=s[i-1]){
                count=1;
            }
            if(count>=3){
                i++;
                continue;
            }

            ans.push_back(s[i]);
            i++;
            
            
        }

        return ans;
    }
};