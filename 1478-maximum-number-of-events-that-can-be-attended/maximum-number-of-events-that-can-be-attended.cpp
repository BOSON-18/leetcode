class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<int>> pq;

        int i = 0, n = events.size();
        int day = 0, count = 0;

        while (i < n || !pq.empty()) {
            if (pq.empty()) {
                day = events[i][0]; // jump to the next event's start day
            }

            // Add all events that start today
            while (i < n && events[i][0] == day) {
                pq.push(events[i][1]);
                i++;
            }

            // Remove events that have already ended
            while (!pq.empty() && pq.top() < day) {
                pq.pop();
            }

            // Attend the event that ends earliest
            if (!pq.empty()) {
                pq.pop();
                count++;
            }

            day++;
        }

        return count;
    }
};
