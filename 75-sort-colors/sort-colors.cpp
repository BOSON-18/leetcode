class Solution {
public:

void swap(vector<int>& nums,int l,int r){
    int temp =nums[l];
    nums[l]=nums[r];
    nums[r]=temp;
}
    void sortColors(vector<int>& nums) {
        int l=0,m=0,r=nums.size()-1;

            while(m<=r){
                if(nums[m]==0){
                    swap(nums,l,m);
                    l++;
                    m++;
                }else if(nums[m]==2){
                    swap(nums,m,r);
                    r--;
                }else{
                    m++;
                }
            }

    }
};