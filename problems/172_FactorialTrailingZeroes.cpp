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
    int trailingZeros(int n) {
        int zeros = 0;
        for (int k = 5; k < n; k*=5) {
            zeros += n / k;
        }
        return zeros;
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;

    Solution solution;
    cout << solution.trailingZeros(n) << endl;
    
    return 0;
}
