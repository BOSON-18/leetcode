class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        
        int maxCnt=0;

        for(int i=0;i<31;i++){
            int cnt=0;
            for(int can : candidates){
                if(can&(1<<i)){
                    cnt++;
                }
            }
            maxCnt=max(cnt,maxCnt);
        }

        return maxCnt;
    }
};