class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //Maximise Profit Buy on one day sell on other can do only once 
        //can sell in future only

//Brute Force 
//Two For Loops -> TC O(N^2)

//Optimise (NLOGN or N) 
//Can't sort because will distort the prices

        int maxProfit=0;
int n=prices.size();
        int buy=prices[0];
        for(int i=1;i<n;i++){
            maxProfit=max(maxProfit,prices[i]-buy);
            buy=min(buy,prices[i]);
        }


return maxProfit;
        
    }
};