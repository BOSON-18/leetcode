class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {

        sort(nums.begin(),nums.end());

        int i=0,j=0;
        int maxBeauty=0;

        while(i<nums.size()){
            while(j<nums.size() && nums[j]<=nums[i]+2*k){
                j++;
            }
            maxBeauty=max(maxBeauty,j-i);
            i++;
        }

        return maxBeauty;
        
    }
};