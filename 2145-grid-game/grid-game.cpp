class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long firstRowRemainingSum =
            accumulate(begin(grid[0]), end(grid[0]), 0LL);

        long long secondRowRemainingSum = 0;

        long long minimizedRobot2Sum = LONG_LONG_MAX;

        for (int r1 = 0; r1 < grid[0].size(); r1++) {
            // Robot1 Took this strategy
            firstRowRemainingSum -= grid[0][r1];
            // ROBOT 2 will try to do the best afeter Robot1 has taken above
            // strategy
            long long bestofRobot2 =
                max(firstRowRemainingSum, secondRowRemainingSum);

            minimizedRobot2Sum = min(minimizedRobot2Sum, bestofRobot2);

            secondRowRemainingSum +=grid[1][r1];
        }
        return minimizedRobot2Sum;
    }
};