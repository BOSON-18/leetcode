class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> ans;

        int size=1;
        vector<int> prev={1};
        ans.push_back(prev);
        size++;
        while(size<=numRows){
            vector<int> curr(size,0);
                curr[0]=1;
                curr[size-1]=1;
            for(int i=1;i<size-1;i++){
                curr[i]=prev[i]+prev[i-1];
            }

            ans.push_back(curr);
            prev=curr;
            size++;
        }
        
        return ans;
    }
};