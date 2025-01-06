class Solution {
public:
    vector<vector<int>> ans;
    void memo(vector<int>& candidates, int target, int index, vector<int>& temp) {
        if (target == 0) { // If we hit the target
            ans.push_back(temp); // Add the valid combination
            return;
        }
        if (target < 0 || index >= candidates.size()) { // If target is negative or index is out of bounds
            return;
        }
        
        // Include the current candidate
        temp.push_back(candidates[index]);
        memo(candidates, target - candidates[index], index, temp); // Stay on the same index to allow repeats
        temp.pop_back();
        
        // Exclude the current candidate and move to the next
        memo(candidates, target, index + 1, temp);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        memo(candidates, target, 0, temp); // Start from the 0th index
        return ans;
    }
};
