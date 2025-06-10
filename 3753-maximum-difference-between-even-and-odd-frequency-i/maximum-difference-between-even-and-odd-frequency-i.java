
class Solution {
    public int maxDifference(String s) {

        HashMap<Character, Integer> mpp = new HashMap<>();

        for (char c : s.toCharArray()) {
            mpp.put(c, mpp.getOrDefault(c, 0) + 1);
        }

        int odd = 0;
        int even = Integer.MAX_VALUE;

        for (Map.Entry<Character, Integer> it : mpp.entrySet()) {
            int freq = it.getValue();
            if (freq % 2 == 1 && freq > odd) {
                odd = freq;
            } else if (freq % 2 == 0 && freq < even) {
                even = freq;
            }
        }

        return odd - even;
    }
}
