class Solution {

    public void reverse(int[] nums,int start,int end){
        int l=start,r=end;

        while(l<r){
            swap(nums,l,r);
            l++;
            r--;
        }
    }

    public void swap(int[] nums,int left,int right){
        int temp=nums[left];
        nums[left]=nums[right];
        nums[right]=temp;
    }
    public void nextPermutation(int[] nums) {

        int n=nums.length;

        int index=-1;

        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                index=i;
                break;
            }
        }

        if(index==-1){
            reverse(nums,0,n-1);
            return ;
        }

        for(int i=n-1;i>index;i--){
            if(nums[i]>nums[index]){
                swap(nums,i,index);
                break;
            }
        }

        reverse(nums,index+1,n-1);

        return ;
        
    }
}