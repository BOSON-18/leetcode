class Solution {
public:

int memo(vector<int>& arr,int index,int previndex,vector<vector<int>>& dp){
    if(index==-1) return 0;
    if(dp[index][previndex+1]!=-1) return dp[index][previndex+1];
    //take or not take
    int take=INT_MIN;
    if(previndex==-1 || arr[index]<arr[previndex]){
        take=1+memo(arr,index-1,index,dp);
    }


    int notTake=memo(arr,index-1,previndex,dp);

    return dp[index][previndex+1]=max(take,notTake);
}
    int lengthOfLIS(vector<int>& nums) {
        //Lets see if greedy works ???

        // Brute Force
        // Will start with every element and will add elements if larger than prev one
        // At last maximum
        // Time Complexity O(N^2)

        // Try All possible ways out from top to bootom 
        // Recursion it is
        // O(2N)
        // vector<int> dp(nums.size(),-1);
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size()+1,-1));
        return memo(nums,nums.size()-1,-1,dp);
        
    }
};