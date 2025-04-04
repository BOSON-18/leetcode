class Solution {
public:
    int memo(vector<int>& arr, int index, int previndex,
             vector<vector<int>>& dp) {
        if (index == -1)
            return 0;
        if (dp[index][previndex + 1] != -1)
            return dp[index][previndex + 1];
        // take or not take
        int take = INT_MIN;
        if (previndex == -1 || arr[index] < arr[previndex]) {
            take = 1 + memo(arr, index - 1, index, dp);
        }

        int notTake = memo(arr, index - 1, previndex, dp);

        return dp[index][previndex + 1] = max(take, notTake);
    }
    int lengthOfLIS(vector<int>& arr) {
        // Lets see if greedy works ???

        // Brute Force
        // Will start with every element and will add elements if larger than
        // prev one At last maximum Time Complexity O(N^2)

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
        // considering elements from 0 to i, and having the previous element at
        // index j.
        //   int n = arr.size();

        // dp[i][j] will store the length of the longest increasing subsequence
        // considering elements from 0 to i, and having the previous element at
        // index j.
        // vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        // for(int ind = n-1; ind>=0; ind --){
        //     for (int prev_index = ind-1; prev_index >=-1; prev_index --){

        //         int notTake = 0 + dp[ind+1][prev_index +1];

        //         int take = 0;

        //         if(prev_index == -1 || arr[ind] > arr[prev_index]){

        //             take = 1 + dp[ind+1][ind+1];
        //         }

        //         dp[ind][prev_index+1] = max(notTake,take);

        //     }
        // }

        // return dp[0][0];

      // Iterate over each element (index)
    // for (int index = 0; index < n; index++) {
    //     for (int prevIndex = -1; prevIndex < index; prevIndex++) {
    //         int length = 0;

    //         // If index > 0, carry over the previous value
    //         if (index > 0) {
    //             length = 0 + dp[index - 1][prevIndex + 1];
    //         }

    //         // Check if we can take the current element
    //         if (prevIndex == -1 || arr[prevIndex] < arr[index]) {
    //             // If index == 0, you can always take the first element
    //             length = max(length, 1 + (index > 0 ? dp[index - 1][index] : 0));
    //         }

    //         dp[index][prevIndex + 1] = length;  // Store result in DP table
    //     }
    // }

    // // Return the maximum length from the last column of dp table
    // int maxLength = 0;
    // for (int i = 0; i < n; i++) {
    //     maxLength = max(maxLength, dp[i][n]);
    // }

    // return maxLength;

vector<int> sorted;

for(int i=0;i<n;i++){
    auto it = lower_bound(begin(sorted),end(sorted),arr[i]);

    if(it==end(sorted)) sorted.push_back(arr[i]);
    else *it=arr[i];
}

    return sorted.size();
    }
};