class Solution {
public:
int n;

bool memo(vector<int>& nums,int index,vector<int>& dp){

    if(index==n-1) return true;

    if(dp[index]!=-1) return dp[index];

    if(nums[index]==0) return dp[index]=false;

    for(int i=1;i<=nums[index];i++){
        if(memo(nums,index+i,dp)) return dp[index]=true;
    }
    return dp[index]=false;
}
    bool canJump(vector<int>& nums) {
        n=nums.size();
        vector<int> dp(n,-1);

        return memo(nums,0,dp);
        
    }
};