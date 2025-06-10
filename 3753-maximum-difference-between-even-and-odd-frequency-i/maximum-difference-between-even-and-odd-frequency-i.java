
class Solution {
    public int maxDifference(String s) {

        HashMap<Character, Integer> mpp = new HashMap<>();
        int[] arr = new int[26];

        for (char c : s.toCharArray()) {
            // mpp.put(c, mpp.getOrDefault(c, 0) + 1);
            arr[c-'a']=arr[c-'a']+1;
        }

        int odd = 0;
        int even = Integer.MAX_VALUE;

        // for (Map.Entry<Character, Integer> it : mpp.entrySet()) {
       for(int it:arr){
            int freq = it;
            if (freq % 2 == 1 && freq > odd) {
                odd = freq;
            } else if (freq % 2 == 0 && freq < even && freq!=0) {
                even = freq;
            }
        }

        return odd - even;
    }
}
