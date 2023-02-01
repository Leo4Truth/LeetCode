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
    virtual bool digitCount(string num) = 0;
};

class Solution_init : public Solution {
public:
    bool digitCount(string num) {
        unordered_map<int, int> count;
        for (int i = 0; i < num.size(); i++) {
            if (count.count(num[i] - '0') == 0) count[num[i] - '0'] = 1;
            else count[num[i] - '0'] = count[num[i] - '0'] + 1;
        }
        for (int i = 0; i < num.size(); i++) {
            if (count[i] != (num[i] - '0')) return false;
        }
        return true;
    }

private:
};

int main(int argc, char* argv[]) {
    string num = argc >= 2 ? argv[1] : "";

    Solution *solution = nullptr;

    solution = new Solution_init();
    cout << solution->digitCount(num) << endl;

    return 0;
}
