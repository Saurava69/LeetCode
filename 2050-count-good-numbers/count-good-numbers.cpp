#define mod 1000000007
class Solution {
public:
    long long modPow(long long base, long long exp) {
        long long result = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) result = (result * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2;  // even-positioned digits (0,2,4,6,8)
        long long odd = n / 2;         // odd-positioned digits (prime digits)

        long long ans = (modPow(5, even) * modPow(4, odd)) % mod;
        return ans;
    }
};
