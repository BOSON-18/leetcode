class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {

        int arr[1001]={0};

        for(auto& it:trips){
            arr[it[1]] += it[0];
            arr[it[2]] -=it[0];
        }

        int curr=0;
        for(int& i: arr){
            curr+=i;
            if(curr>capacity) return false;
        }

        return true;
        
    }
};