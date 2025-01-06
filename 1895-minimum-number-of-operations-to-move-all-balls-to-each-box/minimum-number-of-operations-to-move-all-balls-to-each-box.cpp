class Solution {
public:
    vector<int> brute(string boxes) {
        int n = boxes.size();
        vector<int> ans(n, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (boxes[j] == '1')
                    ans[i] += abs(j - i);
            }
        }

        return ans;
    }

    vector<int> optimal(string boxes) {
        int n = boxes.size();
        vector<int> answer(n, 0);

        int cumValue = 0,  cumValueSum = 0;

        // Find Moves for all left balls to index i
        for (int i = 0; i < n; i++) {
            answer[i] = cumValueSum;
            cumValue += boxes[i] == '0' ? 0 : 1;
            cumValueSum += cumValue;
        }
        cumValue = 0;
        cumValueSum = 0;
        for (int i = n - 1; i >= 0; i--) {
            answer[i] += cumValueSum;
            cumValue += boxes[i] == '0' ? 0 : 1;
            cumValueSum += cumValue;
        }

        return answer;
    }

    vector<int> minOperations(string boxes) {
        // BruteForce
        // return brute(boxes);
        return optimal(boxes);
    }
};