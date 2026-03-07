class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // return indices
        // cant sort as sorting will change the indices of the element

        // brute force is O(N^2) 2 frr loop kaam khtm

        // better map bnake dekh lo

        unordered_map<int, int> mpp;
        int n = nums.size();
       for(int i=0;i<n;i++){
        int req = target-nums[i];
        if(mpp.find(req)!=mpp.end()) return {i,mpp[req]};
        mpp[nums[i]]=i;
       }

       return {-1,-1};
    }
};