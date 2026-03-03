class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {

        map<int,int> mpp;
        
        for(int it:arr1){
            mpp[it]++;
        }
        int n=arr1.size();
        vector<int> ans(n,0);
        int i=0;
        for(int it:arr2){
            
            int freq = mpp[it];

            while(freq>0){
                ans[i]=it;
                i++;
                freq--;
            }

            mpp.erase(it);

        }

        for(auto it:mpp){
             int freq = it.second;

            while(freq>0){
                ans[i]=it.first;
                i++;
                freq--;
            }

            // mpp.erase(it);
        }

        return ans;
    }
};