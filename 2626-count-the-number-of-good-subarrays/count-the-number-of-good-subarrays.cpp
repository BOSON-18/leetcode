class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0,j=0;
        long long result=0;
        unordered_map<int,int> mpp;
        long long pairs=0;

        while(j<n){
            pairs+=mpp[nums[j]];
            mpp[nums[j]]++;

            while(pairs>=k){
                result+= (n-j);
                mpp[nums[i]]--;
                pairs-=mpp[nums[i]];
                i++;

            }
            j++;
        }

        return result;
    }
};