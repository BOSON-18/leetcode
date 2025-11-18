class Solution {
public:
// vector<int> dp;

// int f(vector<int>& cost,int index){

// 	if(index == 0 || index==1) return cost[index];

	
// 	return cost[index]+ min(f(cost,index-1),f(cost,index-2)) ;
// }
    // int minCostClimbingStairs(vector<int>& cost) {
    //     int n=cost.size();
    //     return min(f(cost,n-1),f(cost,n-2));
        
    // }

    // int memo(vector<int>& cost,int index){
    //     if(dp[index]!=0) return dp[index];
    //     if(index<0) return 0;
    //     if(index == 0 || index ==1) return cost[index];

    //     dp[index] = cost[index] + min (memo(cost,index-1),memo(cost,index-2));
    //     return dp[index];
    // }
    // int minCostClimbingStairs(vector<int>& cost) {
    //     int n=cost.size();
    //     dp.assign(n,0);

    //     return min(memo(cost,n-1),memo(cost,n-2));
        
    // }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n,0);
        dp[0] = cost[0];
        dp[1] = cost[1];

        for(int i=2;i<n;i++){
            dp[i] = min(dp[i-1],dp[i-2])+cost[i];
        }

        return min(dp[n-1],dp[n-2]);
        
    }
};