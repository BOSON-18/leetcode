class Solution {
public:


int t[301];
bool solve(int idx,string& s,unordered_set<string>& st){
    int n=s.size();
    if(idx>=n) return true;

    if(t[idx]!=-1) return t[idx];
    if(st.find(s)!=st.end()) return true;

    for(int i=1;i<=n;i++){
        string temp=s.substr(idx,i);

        if(st.find(temp) != st.end() && solve(idx+i,s,st))  return t[idx]= true;
    }

  return  t[idx]=  false;

}
    bool wordBreak(string s, vector<string>& wordDict) {

        // Brute kya kehta
        // Try to make a string from the dictionary 
        // If the word created is equal to the s.length() then compare it if equal return true

        // Try out all ways 
        // Recursion
      int n=s.length();
      unordered_set<string> st(wordDict.begin(),wordDict.end());
      memset(t,-1,sizeof(t));

      return solve(0,s,st);
        
    }
};