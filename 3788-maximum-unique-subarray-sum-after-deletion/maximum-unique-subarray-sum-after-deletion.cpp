class Solution {
public:
    int maxSum(vector<int>& nums) {

        int sum=-1e9;

        unordered_set<int> mpp;

        for(int it:nums){
            if(mpp.count(it)){
                continue;
            }else{
                mpp.insert(it);
                sum=max({sum,sum+it,it});
            }
        }

        return sum;
        
    }
};