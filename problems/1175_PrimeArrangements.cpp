#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    virtual int numPrimeArrangements(int n) = 0;
};

class Solution_init : public Solution {
public:
    int numPrimeArrangements(int n) {
        if (n <= 2) return 1;
        int cnt = 1;
        for (int i = 3; i <= n; i++) {
            if (isPrime(i)) cnt++;
        }
        return (int) (factorial(cnt) * factorial(n - cnt) % MOD);
    }

private:
    const int MOD = 1e9 + 7;

    bool isPrime(int n) {
        if (n <= 1) return false;
        int t = 1, m = 2, p = n;
        while (p) { // 快速幂取模
            if (p % 2) t = ((long long)t * m) % n;
            m = (m * m) % n;
            p >>= 1;
        }
        t = (t - 2) % n;
        return t == 0;
    }

    long factorial(int n) {
        long res = 1;
        for (int i = 1; i <= n; i++) {
            res *= i;
            res %= MOD;
        }
        return res;
    }

    long permutation(int m, int n) {
        long p = 1;
        for (int i = 0; i < n; i++) {
            p *= m - i;
            p %= MOD;
        }
        return p;
    }

    long combination(int m, int n) {
        long numerator = 1, denominator = 1;
        for (int i = 0; i < n; i++) {
            numerator *= m - i;
            numerator %= MOD;
            denominator *= 1 + i;
            denominator %= MOD;
        }
        return numerator / denominator;
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;

    Solution *solution = nullptr;

    solution = new Solution_init();
    cout << solution->numPrimeArrangements(n) << endl;

    return 0;
}
