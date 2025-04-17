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
        for(int i=0;i<sq;i++){
            nums[i]=i+1;
        }

       vector<vector<int>> dp(sq,vector<int>(n+1,INT_MAX));

        return f(nums,sq-1,n,dp);
        
    }
};