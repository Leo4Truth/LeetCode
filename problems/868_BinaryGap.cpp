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
    virtual int binaryGap(int n) = 0;
};

class Solution_init : public Solution {
public:
    int binaryGap(int n) {
        vector<int> binary;
        while (n > 0) {
            binary.push_back(n % 2);
            n /= 2;
        }
        int d = 0;
        int last = -1;
        for (int i = 0; i < binary.size(); i++) {
            if (binary[i] == 1) {
                if (last == -1) last = i;
                else {
                    d = i - last > d ? i - last : d;
                    last = i;
                }
            }
        }
        return d;
    }

private:
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;

    Solution *solution = nullptr;

    solution = new Solution_init();
    cout << solution->binaryGap(n) << endl;

    return 0;
}
