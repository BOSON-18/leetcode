class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {

        long long low = 1, high = *min_element(ranks.begin(),ranks.end())*1LL * cars * cars ;

        while (low < high) {
            long long mid = low + (high - low) / 2;
            long long carsRepaired = 0;

            for (auto rank : ranks) {
                carsRepaired += sqrt(1.0 * mid / rank);
            }

            if (carsRepaired >= cars) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};