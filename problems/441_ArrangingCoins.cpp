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
    int arrangeCoins(int n) {
        int row = 0;
        while (n > 0) {
            row++;
            n -= row;
        }
        return n == 0 ? row : row - 1; 
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;

    Solution solution;
    cout << solution.arrangeCoins(n) << endl;

    return 0;
}
