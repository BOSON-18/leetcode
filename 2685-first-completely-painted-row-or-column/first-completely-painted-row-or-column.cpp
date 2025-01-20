class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        unordered_map<int, int> mpp;
        for (int i = 0; i < arr.size(); i++) {
            mpp[arr[i]] = i;
        }
        int result=INT_MAX;
        for(int row=0;row<n;row++){
            int maxIndex=INT_MIN;
            for(int col=0;col<m;col++){
                int val=mat[row][col];
                int index=mpp[val];
                maxIndex=max(maxIndex,index);
            }
            result=min(result,maxIndex);
        }

        for(int col=0;col<m;col++){
            int maxIndex=INT_MIN;
            for(int row=0;row<n;row++){
                int val=mat[row][col];
                int index=mpp[val];
                maxIndex=max(maxIndex,index);
            }
            result=min(result,maxIndex);
        }

        return result;
    }
};