class Solution {
public:

bool isSubset(vector<int>& freq2,vector<int>& temp){
    for(int i=0;i<26;i++){
        if(freq2[i]>temp[i]) return false;
    }
    return true;
}
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {

        vector<string> result;
        vector<int> freq2(26,0);

        for(int i=0;i<words2.size();i++){
            int temp[26]={0};

            for(char& ch: words2[i]){
                temp[ch-'a']++;
                freq2[ch-'a']=max(freq2[ch-'a'],temp[ch-'a']);
            }
        }

        for(string& word: words1){
            vector<int> temp(26,0);

            for(char &ch :word){
                temp[ch-'a']++;
            }

            if(isSubset(freq2,temp)) result.push_back(word);
        }
return result;

        
    }
};