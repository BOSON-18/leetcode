class Solution {
    public int[] diStringMatch(String s) {
        int n = s.length();
        int[] ans = new int[n + 1];
        int low = 0, high = n;

        for (int i = 0; i < n; i++) {
            ans[i] = (s.charAt(i) == 'I') ? low++ : high--;
        }
        ans[n] = low;
        return ans;
    }
}
