class Solution {
public:
void reverse(vector<int>& nums,int start,int end){

    while(start<end){
        swap(nums[start],nums[end]);
        start++;
        end--;
    }
}
    void nextPermutation(vector<int>& nums) {

        int n=nums.size();
        int index=-1;
        
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                index=i;
                break;
            }
        }

        if(index==-1){
            reverse(nums,0,n-1);
            return;
        }

        for(int i=n-1;i>index;i--){
            if(nums[i]>nums[index]){
                swap(nums[i],nums[index]);
                break;
            }
        }
        
        reverse(nums,index+1,n-1);
        return ;
        
    }
};