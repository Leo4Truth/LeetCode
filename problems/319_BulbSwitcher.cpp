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
    virtual int bulbSwitch(int n) = 0;
};

class Solution_math : public Solution {
public:
    int bulbSwitch(int n) {
        return sqrt(n + 0.5);
    }

private:
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;

    Solution *solution = nullptr;

    solution = new Solution_math();
    cout << solution->bulbSwitch(n) << endl;

    return 0;
}
