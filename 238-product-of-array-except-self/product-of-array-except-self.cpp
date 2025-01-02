class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //return an array -> arr[i]=Product of all elements / nums[i]
        //But Dont use / operator

        //Brute Force
        //Two For Loops multiply just dont multiply element on index i
        //TC->O(N^2)

        //Optimise
        //(NLOGN or N)
        //Cant sort will leasd to wong ans
        //Will Try O(n)

        //What i need ?
        //arr[i]== prefixProduct and suffix Product
        // Create two arrays prefix and suffix that will store this values

        int n=nums.size();
        vector<int> prefix(n,1);// store product of elements before nums[i]
        vector<int> suffix(n,1);//store product of elements fter nums[i]

        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]*nums[i-1];
        }
        for(int i=n-2;i>=0;i--){
            suffix[i]=suffix[i+1]* nums[i+1];
        }

       vector<int> ans(n);

        for(int i=0;i<n;i++){
            ans[i]=prefix[i]*suffix[i];
        }

        return ans;

    }
};