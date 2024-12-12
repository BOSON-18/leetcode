class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> mpp;

        for(int &num:arr){
            if(mpp.count(num*2 )|| (mpp.count(num/2) && num%2==0)) return true;

            mpp.insert(num);
        }

        return false;
    }
};