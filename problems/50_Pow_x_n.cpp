#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    // Brute Force
    // Time Complexity: O(n)
    double myPow(double x, int n) {
        long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        double ans = 1;
        for (long long i = 0; i < N; i++)
            ans = ans * x;
        return ans;
    }

    // Fast Power Algorithm Recursive
    // Time Complexity: O(logn)
    double myPow_fast_recursive(double x, int n) {
        long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        return fastPow(x, N);
    }

    double fastPow(double x, long long n) {
        if (n == 0) {
            return 1.0;
        }
        double half = fastPow(x, n / 2);
        if (n % 2 == 0) {
            return half * half;
        } else {
            return half * half * x;
        }
    }
    
    // Fast Power Algorithm Iterative
    // Time Complexity: O(logn)
    double myPow_fast_iterative(double x, int n) {
        long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        double ans = 1;
        double current_product = x;
        for (long long i = N; i ; i /= 2) {
            if ((i % 2) == 1) {
                ans = ans * current_product;
            }
            current_product = current_product * current_product;
        }
        return ans;
    }
};

int main(int argc, char* argv[]) {
    double x = argc >= 2 ? stod(argv[1]) : 0.0;
    int n = argc >= 3 ? stoi(argv[2]) : 0;

    Solution solution;
    cout << solution.myPow_fast_iterative(x, n) << endl;

    //system("pause");
    return 0;
}
