class Solution {
public:
    string makeFancyString(string s) {
        int n=s.size();
        if(s.size()<3) return s;
        int low=0,high=0;

        int cons=0;
        char lastChar=s[0];
        string res="";

        while(high<n){
            if(high==0){
                res.push_back(s[high]);
                cons++;
            }

            if(high>0){
                if(s[high]==lastChar){
                    cons++;
                    if(cons>=3){
                        // cons=0;
                        low=high+1;
                        // high=low;
                        // continue;
                    }else{
                        res.push_back(s[high]);
                    }
                }else{
                    lastChar=s[high];
                    cons=1;
                    res.push_back(s[high]);
                }
            }

            high++;
        }
        return res;
    }
};