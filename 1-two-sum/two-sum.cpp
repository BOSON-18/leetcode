class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // return indices
        //nums[ind1]+nums[ind2]==target
        //ind1!=ind2

        //Brute Force two for loops
        //Time Complexity O(N^2)

        //Optimise it 
        //O(NLogN) or O(N)

        //Better O(NlogN)
        //but it will distort the indexes so cant do it
        //Instead Use Space -> Set 

        unordered_map<int,int> mpp;
    int n=nums.size();
        for(int i=0;i<n;i++){
            int T=target-nums[i];
            if(mpp.find(T)!=mpp.end()) return {i,mpp[T]};

            mpp[nums[i]]=i;
        }

        return {-1,-1};
       
        
    }
};