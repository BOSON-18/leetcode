class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        int n = nums.size();

        int cnt1 = 0,el1=INT_MIN,cnt2=0,el2=INT_MIN;

        for(int i=0;i<n;i++){
            int curr= nums[i];

            if(curr == el1) cnt1++;
            else if(curr == el2) cnt2++;
            else if(cnt1==0){
                el1=curr;
                cnt1=1;
            }else if(cnt2==0){
                el2=curr;
                cnt2=1;
            }else{
                cnt1--;
                cnt2--;
            }
        }

        vector<int> ans;
        cnt1=0,cnt2=0;

        for(int it:nums){
            if(it==el1) cnt1++;
            if(it==el2) cnt2++;
        }

        if(cnt1>n/3) ans.push_back(el1);
        if(cnt2>n/3) ans.push_back(el2);
        
        return ans;
    }
};