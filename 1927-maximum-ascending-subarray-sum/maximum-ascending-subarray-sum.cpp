class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {

        int maxi=INT_MIN,sum=nums[0];

        for(int i=1;i<nums.size();i++){
            if(nums[i]<=nums[i-1]){
                maxi=max(maxi,sum);
                sum=nums[i];
                continue;
            }
            sum+=nums[i];
        }
    maxi=max(sum,maxi);
        return maxi;
        
    }
};