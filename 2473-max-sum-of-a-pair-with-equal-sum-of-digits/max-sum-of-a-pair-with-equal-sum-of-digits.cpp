class Solution {
public:

int solve(int num){
    int ans=0;

    while(num){
    ans+=num%10;
    num/=10;
    }
    return ans;
}
    int maximumSum(vector<int>& nums) {

        unordered_map<int,vector<int>> mpp;
        sort(nums.begin(),nums.end());

        for(int it:nums){
            int digitSum=solve(it);
            mpp[digitSum].push_back(it);
        }

        int maxi=-1;

        for(auto it: mpp){
          auto arr=it.second;
        //    if(arr.size()==2) maxi=max(maxi,arr[0]+arr[1]);
             if(arr.size()>=2){
               int n=arr.size();
               maxi=max(arr[n-1]+arr[n-2],maxi);
            }
        }
        return maxi;
    }
};