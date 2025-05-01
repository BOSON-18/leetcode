class Solution {
public:
    int memo(string text1,string text2,int index1,int index2,vector<vector<int>>& dp){
        if(index1==-1 || index2==-1) return 0;

        if(dp[index1][index2]!=-1) return dp[index1][index2];

        int match=0,notMatch=0;

        if(text1[index1]==text2[index2]){
            match=1+memo(text1,text2,index1-1,index2-1,dp);
        }else{
            notMatch=max(memo(text1,text2,index1-1,index2,dp),memo(text1,text2,index1,index2-1,dp));
        }

        return dp[index1][index2]= max(match,notMatch);
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1,-1));
        return memo(text1,text2, text1.size()-1, text2.size()-1,dp);
        
    }
};