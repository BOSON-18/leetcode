class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        ////Find subarray->Continuous with largest sum and return sum not subarray

        //Brute FOrce-.2 For Loops and count max of all

        int n=nums.size();
        int maxSum=INT_MIN,sum=0;

        //if sum<0 we will start new subarray 
//Kadane ALgorithm
        int low=0,high=0;

        while(high<n){
            sum+=nums[high];
            maxSum=max(sum,maxSum);
            if(sum<0){
                sum=0;
                low=high+1;
            }
            high++;

        }

        return maxSum;
    }
};