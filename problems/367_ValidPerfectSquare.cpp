#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
    virtual bool isPerfectSquare(int num) = 0;
};

/**
 * @brief Newton Iterative Method
 * Time Complexity: O(logn)
 * Space Complexity: O(1)
 */
class Solution_newton : public Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 0 || num == 1) return true;
        double x0 = num;
        while (true) {
            double x1 = (x0 + num / x0) / 2;
            if (x0 - x1 < 1e-6) {
                break;
            }
            x0 = x1;
        }
        int x = (int) x0;
        return x * x == num;
    }
};

/**
 * @brief binary search
 * Time Complexity: O(logn)
 * Space Complexity: O(1)
 */
class Solution_binarySearch : public Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 0, r = num;
        while (l <= r) {
            int m = (l + r) / 2;
            int square = m * m;
            if (square < num) l = m + 1;
            else if (square > num) r = m - 1;
            else return true;
        }
        return false;
    }
};

/**
 * @brief brute force
 * Time Complexity: O(sqrt(n)), where n is the maximum value of num
 * Space Complexity: O(1)
 */
class Solution_bf : public Solution {
public:
    bool isPerfectSquare(int num) {
        int x = 0;
        int square = 0;
        while (square <= num) {
            if (square == num) return true;
            x++;
            square = x * x;
        }
        return false;
    }
};

class Solution_sysFunc : public Solution {
public:
    bool isPerfectSquare(int num) {
        int x = (int) sqrt(num);
        return x * x == num;
    }
};

int main(int argc, char* argv[]) {
    int num = argc >= 2 ? stoi(argv[1]) : 0;

    Solution *solution = nullptr;

    solution = new Solution_newton();
    cout << solution->isPerfectSquare(num) << endl;

    solution = new Solution_binarySearch();
    cout << solution->isPerfectSquare(num) << endl;

    solution = new Solution_bf();
    cout << solution->isPerfectSquare(num) << endl;

    solution = new Solution_sysFunc();
    cout << solution->isPerfectSquare(num) << endl;

    return 0;
}
