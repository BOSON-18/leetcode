class Solution {
public:

int f(vector<int>& nums,int index,int target,vector<vector<int>>& dp){
    int square = nums[index]*nums[index];
    if(dp[index][target]!=INT_MAX) return dp[index][target];
    if(index==0 ) return target;
    if(square==target) return 1;

    int take=INT_MAX;
    if(square<=target) take=1+f(nums,index,target-square,dp);
    int notTake=0+f(nums,index-1,target,dp);

    return dp[index][target]=min(take,notTake);

}
    int numSquares(int n) {
        
        int sq=sqrt(n);
        if(sq*sq==n){
            return 1;
        }

        vector<int> nums(sq);
        // for(int i=0;i<sq;i++){
        //     nums[i]=i+1;
        // }
        for(int i=0;i<sq;i++) nums[i]=(i+1)*(i+1);
       vector<vector<int>> dp(sq,vector<int>(n+1,INT_MAX));

       for(int i=0; i<sq;i++){
        dp[i][0]=0;
       }

       for(int t=1;t<=n;t++){
        if(t%nums[0] == 0){
            dp[0][t]=t/nums[0];
        }
       }

       for(int i=1;i<sq;i++){
        for(int t=1;t<=n;t++){
            int notTake=dp[i-1][t];
            int take=INT_MAX;
            if(nums[i] <= t && dp[i][t - nums[i]] != INT_MAX) 
                take=1+dp[i][t-nums[i]];
            dp[i][t]=min(take,notTake);    
        }
       }

       return dp[sq-1][n];

        // return f(nums,sq-1,n,dp);
        
    }
};