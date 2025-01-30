class Solution {
public:
int dp[101];
int memo(vector<int>& nums,int index){
    if(index<0) return 0;
    if(dp[index]!=-1) return dp[index];
    //take or not take
    int take=nums[index]+memo(nums,index-2);
    int notTake=0+memo(nums,index-1);

    return dp[index]=max(take,notTake);
}
    int rob(vector<int>& nums) {

       
        // memset(dp,-1,sizeof(dp));
        memset(dp,0,sizeof(dp));

        //bottom up tabulation
        dp[0]=nums[0];

        for(int i=1;i<nums.size();i++){
            int take=nums[i];
            if(i>1) take+=dp[i-2];

            int notPick=dp[i-1];

            dp[i] =max(take,notPick);
        }
        // return memo(nums,nums.size()-1);
        return dp[nums.size()-1];
        
    }
};