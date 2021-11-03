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
    string toHex(int num) {
        if (num == 0) return "0";
        string hex;
        for (int i = 7; i >= 0; i--) {
            int val = (num >> (4 * i)) & 0xf;
            if (hex.length() > 0 || val > 0) {
                char digit = val < 10 ? (char) ('0' + val) : (char) ('a' + val - 10);
                hex.push_back(digit);
            }
        }
        return hex;
    }
};

int main(int argc, char* argv[]) {
    int num = argc >= 2 ? stoi(argv[1]) : 0;

    Solution solution;
    cout << solution.toHex(num) << endl;

    return 0;
}
