class FindSumPairs {
    private:
    vector<int> arr1;
    vector<int> arr2;
    unordered_map<int,int> mpp;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->arr1=nums1;
        this->arr2=nums2;

        for(int& it:nums2){
            mpp[it]++;
        }
    }
    
    void add(int index, int val) {
        int num = arr2[index];
        if(mpp.find(num)!=mpp.end()){
            mpp[num]--;
            if(mpp[num]==0){
                mpp.erase(num);
            }
        }

        arr2[index]+=val;
        mpp[arr2[index]]++;
        
    }
    
    int count(int tot) {
        int ans=0;

        for(int& it:arr1){
            int x=tot-it;

            if(mpp.find(x)!=mpp.end()){
                ans+=mpp[x];
            }
        }

        return ans;
        
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */