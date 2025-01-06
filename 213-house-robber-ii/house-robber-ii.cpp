class Solution {
public:

int solve(vector<int>& nums){
    int prev1=nums[0];
    int prev2=0;

    for(int i=1;i<nums.size();i++){
        int take= nums[i];
        if(i>1)
        take+=prev2;
        int notTake=0+prev1;

        int curr=max(take,notTake);
        prev2=prev1;
        prev1=curr;
    }

    return prev1;
}
    int rob(vector<int>& nums) {

        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> arr1(begin(nums),end(nums)-1);
        vector<int> arr2(begin(nums)+1,end(nums));
        
        int ans1=solve(arr1);
        int ans2=solve(arr2);

            return max(ans1,ans2);
    }
};