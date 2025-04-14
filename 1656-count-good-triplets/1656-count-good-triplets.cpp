class Solution {
public:

    bool isGood(int x,int y,int z,int a,int b,int c){
        bool first = abs(x-y)<=a ? true:false;
        bool second = abs(z-y)<=b ? true:false;
        bool third = abs(x-z)<=c ? true:false;

        return first&second&third;
    }
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int n=arr.size();
        int count = 0;
        // brute Force says use 3 loops it will work as constraints are small
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    if(isGood(arr[i],arr[j],arr[k],a,b,c)) count++;
                }
            }
        }

        return count;
        
    }
};