class Solution {
public:
    int minimumLength(string s) {

        int freq[26]={0};
        int n=s.size();
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
            if(freq[s[i]-'a']==3) freq[s[i]-'a']-=2;
        }

        int ans=0;

        for(int i=0;i<26;i++){
            // if(freq[i]%3) ans+=freq
            ans+=freq[i];
        }


        return ans;
    }
};