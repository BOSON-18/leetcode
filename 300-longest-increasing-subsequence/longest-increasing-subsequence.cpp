class Solution {
public:
int n;

int memo(vector<int>& nums,vector<vector<int>>& dp,int index,int prevIndex){
    if(index==n) return 0;

    if(dp[index][prevIndex+1]!=-1) return dp[index][prevIndex+1];

    int notTake=memo(nums,dp,index+1,prevIndex);
    int take=0;
    if(prevIndex==-1 || nums[index]>nums[prevIndex]){
        take=1+memo(nums,dp,index+1,index);
    }
   
    return dp[index][prevIndex+1] = max(take,notTake);
}
    int lengthOfLIS(vector<int>& nums) {


         n=nums.size();

        // vector<vector<int>> dp(n,vector<int>(n+1,-1));
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));



        for(int i=n-1;i>=0;i--){
            for(int prevIndex=i-1;prevIndex>=-1;prevIndex--){
                int notTake=dp[i+1][prevIndex+1];
                int take=0;
                if(prevIndex==-1 || nums[i]>nums[prevIndex]){
                    take=1+dp[i+1][i+1];
                }

                dp[i][prevIndex+1]=max(take,notTake);
            }
        }
return dp[0][0];
        // return memo(nums,dp,0,-1);
        
    }
};