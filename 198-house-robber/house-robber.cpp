class Solution {
public:

int memo(vector<int>& arr,int index,vector<int>& dp){
    if(index>=arr.size()) return 0;
    if(dp[index]!=-1) return dp[index];


    // take or not take

    int take=arr[index]+memo(arr,index+2,dp);
    int notTake=0+memo(arr,index+1,dp);

    return dp[index]=max(take,notTake);
}
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return memo(nums,0,dp);
        
    }
};