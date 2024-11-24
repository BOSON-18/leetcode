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

        vector<vector<double>>dp(s.size()+1,vector<double>(t.size()+1,0));// for tabulation
        // vector<vector<int>>dp(s.size(),vector<int>(t.size(),-1));

        for(int i=0;i<=s.size();i++){
            dp[i][0]=1;
        }

        for(int j=1;j<=t.size();j++){
            dp[0][j]=0;
        }

        for(int i=1;i<=s.size();i++){
            for(int j=1;j<=t.size();j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                }
                else 
                    dp[i][j]=dp[i-1][j];
            }
        }

        // return memo(s.size()-1,s,t.size()-1,t,dp);
        return (int)dp[s.size()][t.size()];
    }
};