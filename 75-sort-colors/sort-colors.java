class Solution {

    public void swap(int[] nums,int l,int r){
        int temp=nums[l];
        nums[l]=nums[r];
        nums[r]=temp;
    }

public void sortColors(int[] nums) {
    int l = 0, m = 0, r = nums.length - 1;

    while (m <= r) {
        if (nums[m] == 0) {
            swap(nums, l, m);
            l++;
            m++;
        } else if (nums[m] == 2) {
            swap(nums, m, r);
            r--;
        } else {
            m++;
        }
    }
}

}