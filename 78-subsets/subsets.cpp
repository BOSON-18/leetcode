class Solution {
public:

void rec(int index,vector<int>& nums,vector<int>& arr,vector<vector<int>>& ans){
    if(index>=nums.size()){
        ans.push_back(arr);
        return ;
    }

    //take 
    arr.push_back(nums[index]);
    rec(index+1,nums,arr,ans);
    arr.pop_back();
    rec(index+1,nums,arr,ans);
}
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> arr;

        rec(0,nums,arr,ans);

        return ans;

        
    }
};