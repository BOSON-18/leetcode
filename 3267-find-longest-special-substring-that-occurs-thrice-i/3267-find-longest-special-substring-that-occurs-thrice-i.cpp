class Solution {
public:
    int maximumLength(string s) {

        int n=s.length();
        unordered_map<string,int> mpp;
        int maxLength=-1;


        for(int i=0;i<n;i++){
            string curr="";
            for(int j=i;j<n;j++){
                if(curr.length()==0 || curr.back()==s[j]){
                    curr.push_back(s[j]);
                    mpp[curr]++;
                }else{
                    break;
                }
            }
        }

        for(auto& it:mpp){
            int length=it.first.length();
            if(it.second>=3){
                maxLength=max(maxLength,length);
            }
        }

        return maxLength;
        
    }
};