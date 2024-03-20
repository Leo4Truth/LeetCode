public class Solution1969MinimumNonZeroProductOfTheArrayElements {
    public int minNonZeroProduct(int p) {
        if (p == 1) {
            return 1;
        }
        long mod = 1000000007;
        long x = fastPow(2, p, mod) - 1;
        long y = (long) 1 << (p - 1);
        return (int) (fastPow(x - 1, y - 1, mod) * x % mod);
    }

    private long fastPow(long x, long n, long mod) {
        long res = 1;
        for (; n != 0; n >>= 1) {
            if ((n & 1) != 0) {
                res = res * x % mod;
            }
            x = x * x % mod;
        }
        return res;
    }

    public static void main(String[] args) {
        Solution1969MinimumNonZeroProductOfTheArrayElements solution1969MinimumNonZeroProductOfTheArrayElements =
                new Solution1969MinimumNonZeroProductOfTheArrayElements();
        System.out.println(solution1969MinimumNonZeroProductOfTheArrayElements.minNonZeroProduct(5));
    }
}
