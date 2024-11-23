class Solution {
public:

int memo(int ind1,string& text1,int ind2,string& text2,  vector<vector<int>>& dp){
    if(ind1<0 || ind2<0) return 0;
    if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
   
    if(text1[ind1]==text2[ind2])
        return dp[ind1][ind2]=1+memo(ind1-1,text1,ind2-1,text2,dp);
    else
         return dp[ind1][ind2]=max(memo(ind1-1,text1,ind2,text2,dp),memo(ind1,text1,ind2-1,text2,dp));
}
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        // return memo(n-1,text1,m-1,text2,dp);

       //nsae case 
       //right shift indexs 0=1 1=2 so insetead of i<0 i==0 will be abse case and will return 0
    //    for(int i=0;i<=n;i++){
    //     dp[i][0]=0;
    //     // dp[i][0]=0;
    //    }

    vector<int> prev(m+1,0),curr(m+1,0);
       for(int j=0;j<=m;j++){
        prev[j]=0;
        // dp[0][j]=0;
       }


       //convert to for loops in opposite manner of recurrence

       for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(text1[i-1]==text2[j-1])
                curr[j]=1+prev[j-1];
                // dp[i][j]=1+dp[i-1][j-1];
            else
                curr[j]=max(prev[j],curr[j-1]);    
                // dp[i][j]=max(dp[i-1][j],dp[i][j-1]);    
        }
        prev=curr;
       }

       return prev[m];
    //    return dp[n][m];
    }
};