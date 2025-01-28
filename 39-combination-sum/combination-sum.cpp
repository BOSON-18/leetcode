class Solution {
public:
    vector<vector<int>> ans;
int n;
    void memo(int index, int target, vector<int>& temp,
            vector<int>& arr) {
        if (target == 0) {       
            ans.push_back(temp); 
            return;
        }
        if (target < 0 ||
            index >= n) { 
            return;
        }

        //take or not take
     
            temp.push_back(arr[index]);
            memo(index,target-arr[index],temp,arr);
            temp.pop_back();
            memo(index+1,target,temp,arr);


       
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        n = candidates.size();
        vector<int> temp;

        memo(0, target, temp, candidates);
        return ans;
    }
};