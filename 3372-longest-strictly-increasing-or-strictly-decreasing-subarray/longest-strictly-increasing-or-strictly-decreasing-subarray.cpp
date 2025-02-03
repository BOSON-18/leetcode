class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {

        int maxi=1,mini=1;

        int count=1;

        for(int i=1;i<nums.size();i++){

            if(nums[i]>nums[i-1]) count++;
            else count=1;
            maxi=max(maxi,count);
        }
        count=1;

        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1])count++;
            else count=1;
            mini=max(mini,count);
        }

        return max(mini,maxi);
    }
};