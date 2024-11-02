class Solution {
public:
    bool isCircularSentence(string sentence) {

        int n=sentence.size();

        for(int i=0;i<n;i++){
            if(sentence[i]==' ' && sentence[i-1]!=sentence[i+1] ) return false;
            else if(i==n-1 && sentence[i]!=sentence[0]) return false;
        }

        return true;
        
    }
};