class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n=nums.size();

        unordered_map<int,int> mpp;

        int low=0,high=0;

        for(int it:nums){
            mpp[it]++;
        }
int count=0;
        int distinct=mpp.size();
        mpp.clear();

        while(high<n){
            mpp[nums[high]]++;

            if(mpp.size()==distinct){
                count+=n-high;
                while(mpp.size()==distinct){
                    if(mpp[nums[low]]==1){
                        mpp.erase(nums[low]);
                    }else{
                        mpp[nums[low]]--;
                        count+=n-high;
                    }
                    low++;
                }
            }
            high++;
        }
        return count;
    }
};