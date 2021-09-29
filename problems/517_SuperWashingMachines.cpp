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
    int findMinMoves(vector<int>& machines) {
        return 0;
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    vector<int> machines;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        machines.push_back(x);
    }

    Solution solution;
    cout << solution.findMinMoves(machines) << endl;

    return 0;
}
