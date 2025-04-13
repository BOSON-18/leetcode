class Solution {
    private int mod =(int) 1e9 + 7;

    private long findPower(long a, long b) {
        if (b == 0)
            return 1;

        long half = findPower(a, b / 2);
        long result = (half * half) % mod;

        if (b % 2 == 1)
            result = (result * a) % mod;
        return result;
    }

    public int countGoodNumbers(long n) {
        long result=  findPower(5,(n+1)/2)*findPower(4,n/2) % mod;

        return (int) result;

    }
}