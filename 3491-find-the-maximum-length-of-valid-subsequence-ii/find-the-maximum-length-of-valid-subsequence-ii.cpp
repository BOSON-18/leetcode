class Solution {
public:


    int maximumLength(vector<int>& nums,int k) {

        int n=nums.size();

        vector<int> dp1(n,1);

        int maxSub=1;
        vector<int> dp0(n,1);

        vector<vector<int>> dp(k,vector<int>(n,1));

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                int mod = (nums[i]+nums[j])%k;

                // if(mod==1){
                //     dp1[i]=max(dp1[i],1+dp1[j]);
                //     maxSub = max(maxSub,dp1[i]);
                // }else{
                //        dp0[i]=max(dp0[i],1+dp0[j]);
                //     maxSub = max(maxSub,dp0[i]);
                // }

                dp[mod][i]=max(dp[mod][i],1+dp[mod][j]);
                maxSub=max(maxSub,dp[mod][i]);
            }
        }

        // for(int i=1;i<n;i++){
        //     for(int j=0;j<i;j++){
        //         int mod = (nums[i]+nums[j])%k;

        //         if(mod==0){
        //             dp0[i]=max(dp0[i],1+dp0[j]);
        //             maxSub = max(maxSub,dp0[i]);
        //         }
        //     }
        // }
        return maxSub;
    }
};