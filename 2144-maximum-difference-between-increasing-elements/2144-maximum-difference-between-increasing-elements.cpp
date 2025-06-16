class Solution {
public:
    int maximumDifference(vector<int>& nums) {

        int maxi= INT_MIN;
        int n=nums.size();
        vector<int> prefixMin(n);
        prefixMin[0]=nums[0];
        for(int i=1;i<n;i++){
            prefixMin[i]=min(nums[i],prefixMin[i-1]);
        }

        for(int i=1;i<n;i++){
            if(nums[i]>prefixMin[i]){
                maxi=max(maxi,nums[i]-prefixMin[i]);
            }
        }

        if(maxi==INT_MIN) return -1;
        return  maxi;




        
    }
};