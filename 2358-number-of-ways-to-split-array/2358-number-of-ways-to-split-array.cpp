class Solution {
public:

bool isValid(vector<int>& arr,int index,int size){
    int sum1=0,sum2=0;
    int firstElement=index+1;
    int lastElement=size-index-1;
    int i=0;
    while(firstElement--){
        sum1+=arr[i++];
    }
    i=size-1;
    while(lastElement--){
        sum2+=arr[i--];
    }

    if(sum1>=sum2){ 
         cout<<"Index"<<index<<" ";
    return true;
    }
    return false;
}
    int waysToSplitArray(vector<int>& nums) {
        // split array at index
        //index cant be the last element
        //Assume trying to split at index 1
        //i+1 elements -> 10,4,-8 )upto index 2 1+1
        //n-i-1->4-1-1 =2 last 2 elements -> -8,7 
        //Sum of front -> 6 Sum of last->-1
        //6>-1 valid count++

        //Brute Force
        //Using a for loop iterating from 0 to n-2 index as cant split at last index
        //for every index i will check if valid or not will take 2 different for loops nested within the main for loop
        //if satisy the condition count++

        int n=nums.size();

        // int valid=0;

        // for(int i=0;i<n-1;i++){
        //     isValid(nums,i,n) ? valid++:valid+=0;
        // }

     vector<long long> prefix(n, 0), suffix(n, 0); // Initialize with size n and default values 0
for (int i = 0; i < n; i++) {
    prefix[i] = (i == 0 ? nums[i] : prefix[i - 1] + nums[i]);
}
for (int i = n - 1; i >= 0; i--) {
    suffix[i] = (i == n - 1 ? nums[i] : suffix[i + 1] + nums[i]);
}

int valid = 0; // Initialize valid
for (int i = 0; i < n - 1; i++) {
    if (prefix[i] >= suffix[i + 1]) valid++;
}

return valid;


        
    }
};