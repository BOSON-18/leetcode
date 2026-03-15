class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int low =0,high=0;

        int n=nums.size();



       while(high<n){
        if(nums[high]!=nums[low]){
            nums[low+1]=nums[high];
            low++;
        }
        high++;
       }
       return low+1;
        
    }
};