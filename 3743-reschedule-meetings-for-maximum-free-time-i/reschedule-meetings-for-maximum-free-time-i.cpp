class Solution {
public:

int solve(int eventTime, int k, vector<int>& startTime, vector<int>& endTime){
  int n = startTime.size();
    vector<int> gaps;
    gaps.push_back(startTime[0]);
    for (int i = 1; i < n; i++) {
        gaps.push_back(startTime[i] - endTime[i - 1]);
    }
    gaps.push_back(eventTime - endTime[n - 1]);
    int windowSum = 0;
    for (int i = 0; i < k + 1; i++) {
        windowSum += gaps[i];
    }
    int maxFree = windowSum;
    for (int i = k + 1; i < gaps.size(); i++) {
        windowSum += gaps[i] - gaps[i - (k + 1)];
        maxFree = max(maxFree, windowSum);
    }
    return maxFree;
}
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {

        return solve(eventTime,k,startTime,endTime);
    }
};