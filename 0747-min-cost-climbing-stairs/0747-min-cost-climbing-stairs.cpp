class Solution {
public:
int dp[1001];
int rec(int index,vector<int>& cost){
    if(dp[index]!=-1) return dp[index];
    if(index==0 || index==1) return cost[index];
    if(index<0) return 0;

    return dp[index]=cost[index]+min(rec(index-1,cost),rec(index-2,cost));
}
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        memset(dp,-1,sizeof(dp));
        return min(rec(n-1,cost),rec(n-2,cost));
        
    }
};