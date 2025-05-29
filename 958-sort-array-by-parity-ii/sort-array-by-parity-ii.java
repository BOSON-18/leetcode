class Solution {
    public int[] sortArrayByParityII(int[] nums) {
        int n = nums.length;
        int i = 0, j = 1;

        while (i < n && j < n) {
            if (i % 2 == 0 && nums[i] % 2 != 0) {
                while (j < n && nums[j] % 2 != 0) j++;
                if (j < n) swap(nums, i, j);
                i++;
            } else if (i % 2 != 0 && nums[i] % 2 == 0) {
                //inde odd but value even 
                // skip even values
                while (j < n && nums[j] % 2 == 0) j++;
                if (j < n) swap(nums, i, j);
                i++;
            }else{
                i++;
                j++;
            }
        }

        return nums;
    }

    private void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}
