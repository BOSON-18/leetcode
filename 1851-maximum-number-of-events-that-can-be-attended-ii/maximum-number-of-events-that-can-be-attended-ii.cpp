class Solution {
public:
int n;
vector<vector<int>> dp;
int f(vector<vector<int>>& arr,int index,int k){

    if(k==0 || index==n) return 0;
    // if(index==n-1){
    //     auto it=arr[index];
    //     int s=it[0],e=it[1],value=it[2];

    //     if(s>end){
    //         return value;
    //     }
    //     return 0;
    // }
    if(dp[index][k]!=-1) return dp[index][k];
        auto it=arr[index];
        int s=it[0],e=it[1],value=it[2];

        int notTake=0+f(arr,index+1,k);

    // int j=index+1;
    // for(;j<n;j++){
    //     if(arr[j][0]>arr[index][1])break;
    // }
    //upper BOund use krlo
    vector<int> temp={e,INT_MAX,INT_MAX};
  int j= upper_bound(arr.begin()+index+1,arr.end(),temp)-arr.begin();
        int take=0;
        // if(s>end){
            take = value+f(arr,j,k-1);
        // }


        return dp[index][k]=max(take,notTake);
    
}
    int maxValue(vector<vector<int>>& events, int k) {
        n=events.size();
        sort(begin(events),end(events));
        // dp.resize(n+1,vector<int>(k+1,-1));
        dp.resize(n+1,vector<int>(k+1,0));
        vector<int> nextIndex(n);
        for(int i=0;i<n;i++){
            vector<int> temp ={events[i][1],INT_MAX,INT_MAX};
            nextIndex[i]=upper_bound(events.begin()+i+1,events.end(),temp)-events.begin();
        }

        for(int i=n-1;i>=0;i--){
            for(int j=1;j<=k;j++){
                int notTake=dp[i+1][j];
                int take=events[i][2]+dp[nextIndex[i]][j-1];

                dp[i][j]=max(take,notTake);
            }
        }

        return dp[0][k];
        // return f(events,0,k);
        
    }
};