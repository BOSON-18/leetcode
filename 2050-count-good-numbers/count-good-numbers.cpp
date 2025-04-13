class Solution {
public:
    int mod = 1e9 + 7;

    int findPower(long long a, long long b) {
        if (b == 0)
            return 1;

        long long half = findPower(a, b / 2);
        long long result = (half * half) % mod;

        if (b % 2 == 1) {
            result = (result * a) % mod;
        }
        return result;
    }
    int countGoodNumbers(long long n) {

        return (long long) findPower(5, (n + 1) / 2) * findPower(4, n / 2) %mod;
    }
};