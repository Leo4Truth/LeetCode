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
    bool canWinNim(int n) {
        return (n % 4) > 0 && n / 4 >= 0;
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;

    Solution solution;
    cout << solution.canWinNim(n) << endl;

    return 0;
}
