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
    int lengthOfLIS(vector<int>& arr) {
        //Lets see if greedy works ???

        // Brute Force
        // Will start with every element and will add elements if larger than prev one
        // At last maximum
        // Time Complexity O(N^2)

        // Try All possible ways out from top to bootom 
        // Recursion it is
        // O(2N)
        // vector<int> dp(nums.size(),-1);
        // vector<vector<int>> dp(nums.size(),vector<int>(nums.size()+1,-1));
        // vector<vector<int>> dp(nums.size(),vector<int>(nums.size()+1,0));
        // return memo(nums,nums.size()-1,-1,dp);

        // base case??
        // prevIndex==-1 which means only one way
          int n = arr.size();
    
    // dp[i][j] will store the length of the longest increasing subsequence
    // considering elements from 0 to i, and having the previous element at index j.
    //   int n = arr.size();

    // dp[i][j] will store the length of the longest increasing subsequence
    // considering elements from 0 to i, and having the previous element at index j.
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    
    for(int ind = n-1; ind>=0; ind --){
        for (int prev_index = ind-1; prev_index >=-1; prev_index --){
            
            int notTake = 0 + dp[ind+1][prev_index +1];
    
            int take = 0;
    
            if(prev_index == -1 || arr[ind] > arr[prev_index]){
                
                take = 1 + dp[ind+1][ind+1];
            }
    
            dp[ind][prev_index+1] = max(notTake,take);
            
        }
    }
    
    return dp[0][0];
  


    }
};