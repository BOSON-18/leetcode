
class Solution {
    public int numberOfPoints(List<List<Integer>> nums) {
        int n = nums.size();

        // Sort based on starting point
       nums.sort(Comparator.comparingInt(a -> a.get(0)));
    
        int mini = nums.get(0).get(0);
        int maxi = nums.get(0).get(1);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int start = nums.get(i).get(0);
            int end = nums.get(i).get(1);

            if (start <= maxi) {
                // Overlap
                maxi = Math.max(maxi, end);
            } else {
                ans += (maxi - mini + 1);
                mini = start;
                maxi = end;
            }
        }

        ans += (maxi - mini + 1);
        return ans;
    }
}
