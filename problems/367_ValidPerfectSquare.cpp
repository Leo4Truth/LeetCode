#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    virtual bool isPerfectSquare(int num) = 0;
};

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

int main(int argc, char* argv[]) {
    int num = argc >= 2 ? stoi(argv[1]) : 0;

    Solution *solution = nullptr;

    solution = new Solution_newton();
    cout << solution->isPerfectSquare(num) << endl;

    return 0;
}
