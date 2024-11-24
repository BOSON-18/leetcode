class Solution {
public:

    int memo(int ind1,string& s,int ind2,string& t,vector<vector<int>>& dp){

        if(ind2<0) return 1;
        if(ind1<0) return 0;

        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];

        if(s[ind1]==t[ind2]){
            return  dp[ind1][ind2]=(memo(ind1-1,s,ind2,t,dp)+memo(ind1-1,s,ind2-1,t,dp));
        }
        else 
            return dp[ind1][ind2]=memo(ind1-1,s,ind2,t,dp);
    } 
    int numDistinct(string s, string t) {

        vector<vector<int>>dp(s.size(),vector<int>(t.size(),-1));

        return memo(s.size()-1,s,t.size()-1,t,dp);
        
    }
};