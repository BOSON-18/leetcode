class Solution {
public:

int memo(int ind,vector<int>& nums,vector<int>& dp){
    if(ind<0) return 0;
    if(ind == 0) return nums[0];

    if(dp[ind]!=-1) return dp[ind];

    //take not take
    int take=nums[ind]+memo(ind-2,nums,dp);
    int notTake=0+memo(ind-1,nums,dp);

    return dp[ind]=max(take,notTake); 
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);

        // return memo(n-1,nums,dp);

        //tabulation

        dp[0]=nums[0];


        // for(int i=1;i<n;i++){
        //     int pick=nums[i];
        //     if(i>1){
        //         pick+=dp[i-2];
        //     }
        //     int notPick=dp[i-1];
        //      dp[i] = max(pick, notPick);

        // }

        // return dp[n-1];

        //space optimize

        int prev=nums[0];
        int prev2=0;
        for(int i=1;i<n;i++){
            int take=nums[i];
            if(i>1) take+=prev2;
            int notTake=0+prev;

            int curr=max(notTake,take);
            prev2=prev;
            prev=curr;

        }

        return prev;
    }
};