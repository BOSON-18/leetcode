class Solution {
public:
int MOD=1e9+7;
    int numTilings(int n) {

        if(n==1 || n==2) return n;

        vector<int> dp(n+1,0);
        dp[1]=1;
       dp[2]=2;
       dp[3]=5;
        for(int i=4;i<=n;i++){
            dp[i]=(2*dp[i-1]%MOD+dp[i-3]%MOD)%MOD;
        }
        return dp[n];
        
    }
};