class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        //return ture if any value appears at least twice

        //Brute Force 
        //Two For Loops 
        //Check for every Element ahead 
        //Time Complexity ->o(N^2)

        //Optimise
        //O(NLOGN,N)
        //We can sort here
        int n=nums.size(); 
    if(n==0) return false;
        sort(begin(nums),end(nums));
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]) return true;
        }
        return false;
        
    }
};