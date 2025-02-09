class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n=nums.size();

        long long total_pairs=(long long) n*(n-1)/2;

        long long good_pairs=0;

        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++){
            int diff=nums[i]-i;

            good_pairs+=mpp[diff];
            mpp[diff]++;
        }        

        return total_pairs-good_pairs;
    }
};