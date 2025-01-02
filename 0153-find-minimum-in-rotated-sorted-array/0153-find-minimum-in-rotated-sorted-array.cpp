class Solution {
public:
    void binarySearch(int low, int high, int& mini, vector<int>& nums) {

        while (low <= high) {
            int mid = (low + high) / 2;

            if (nums[mid] < mini) {
                high = mid - 1;
            } else
                low = mid + 1;

            mini = min(mini, nums[mid]);
        }

       
    }
    int findMin(vector<int>& nums) {

        // array was initially sorted
        // Then notated n no of time to right
        // unique elements
        // Return the Minimum element of the array

        // Brute Force Appoach
        // Linear Search -> O(N)

        // optimize -> O(logN)
        // We know that the array is sorted from index 0 to the index after
        // which the next element is smaller than the previous
        //  Ex-> aray is sorrted from 3,4,5 and 1,2
        // We can apply Binary Search for finding the smallest

        int mini = INT_MAX;
        int n = nums.size();
        int low = 0, high = n - 1;

        if (nums[0] < nums[n - 1])
            return nums[0];
        int mid = (low + high) / 2;
        mini = min(mini, nums[mid]);
        if (nums[low] > nums[high] && nums[mid] > nums[high]) {
            // smallest elemetn in right side

            low = mid + 1;
            binarySearch(low, high, mini, nums);
        } else {
            high = mid - 1;
            binarySearch(low, high, mini, nums);
        }
        return mini;
    }
};