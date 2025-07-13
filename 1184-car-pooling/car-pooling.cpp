class Solution {
public:

static bool customComparison(vector<int> a, vector<int> b)
{
    
    return a[1] < b[1]; 
}
    bool carPooling(vector<vector<int>>& trips, int capacity) {

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        sort(begin(trips),end(trips),customComparison);

        for (auto& it : trips) {
            int passenger = it[0], pickup = it[1], drop = it[2];

            while (!pq.empty()) {
                pair<int, int> top = pq.top();
                int e = top.first;
                int p = top.second;

                if (e <= pickup) {
                    capacity += p;
                    pq.pop();
                } else
                    break;
            }

            if (capacity < passenger)
                return false;

            capacity -= passenger;
            pq.push({drop,passenger});
        }
        return true;
    }
};