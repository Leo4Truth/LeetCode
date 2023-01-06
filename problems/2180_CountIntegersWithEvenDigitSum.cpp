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
    virtual int countEven(int num) = 0;
};

class Solution_init : public Solution {
public:
    int countEven(int num) {
        int count = 0;
        for (int n = num; n > 0; n--) {
            if (digitSum(n) % 2 == 0) count++;
        }
        return count;
    }

private:
    int digitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;

    Solution *solution = nullptr;

    solution = new Solution_init();
    cout << solution->countEven(n) << endl;

    return 0;
}
