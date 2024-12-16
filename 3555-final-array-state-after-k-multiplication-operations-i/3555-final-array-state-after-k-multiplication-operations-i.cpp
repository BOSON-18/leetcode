class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> booby;
        for(int i=0; i<nums.size();i++){
            booby.push({nums[i],i});
        }
        for(int i=k;i>0;i--){
            pair<int,int> temp=booby.top();
            booby.pop();
            int tempMul=temp.first;
            tempMul*=multiplier;
            nums[temp.second]=tempMul;
            booby.push({tempMul,temp.second});
        }
        
        return nums;
    }
};