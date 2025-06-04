class Solution {

     public static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    
    public void reverse(int[] nums,int start,int end){
        int n=nums.length;

        int left=start,right=end;

        while(left<right){
           swap(nums,left,right);
            left++;
            right--;
        }
    }
    public void rotate(int[] nums, int k) {

        int n=nums.length;
        if(k%n==0) return ;
        k%=n;
      reverse(nums,n-k,n-1);
        reverse(nums,0,n-k-1);
        reverse(nums,0,n-1);

       
        
    }
}