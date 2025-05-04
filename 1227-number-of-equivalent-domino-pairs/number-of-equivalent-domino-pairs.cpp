class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int n=dominoes.size();
        unordered_map<int,int> mpp;

        int count=0;

        for(auto& domino:dominoes){
            int key = min(domino[0], domino[1]) * 10 + max(domino[0], domino[1]);
            mpp[key]++;
        }

        for(auto& it:mpp){
            int freq=it.second;
            count += (freq*(freq-1))/2; //nC2 = N!/2!*(N-2)!
        }

        return count;
        
    }
};