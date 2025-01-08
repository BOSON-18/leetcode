class Solution {
public:

bool isPrefixSuffix(string& one,string& two){
    int n=one.size(),m=two.size();
    int i=0;

    while(i<n){
        if(one[i]!=two[i]) return false;
        i++;
    }

    i=n-1;
    int j=m-1;

    while(i>=0){
        if(one[i]!=two[j]) return false;
        i--;
        j--;
    }

    return true;
}
    int countPrefixSuffixPairs(vector<string>& words) {

        int n=words.size(),count=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(i==j) continue;
                if(words[i].size()<=words[j].size()){
                    if(isPrefixSuffix(words[i],words[j])) count++;
                }
            }
        }

        return count;
    }
};