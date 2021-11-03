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
    // greedy
    int findMinMoves(vector<int>& machines) {
        int n = machines.size();
        if (n == 0 || n == 1) return 0;

        int total = 0;
        for (auto num : machines) total += num;
        if (total % n != 0) return -1;
        int avg = total / n;

        int sum = 0;
        int res = 0;
        for (auto num : machines) {
            num -= avg; // the amount to move out (if < 0 then move in)
            // separate machines into two group
            // machines[0...i-1] as group A
            // machines[i...n-1] as group B
            // sum is the total amount to move out from A to B (if < 0 then move in)
            sum += num;
            // consider the move steps in two situations:
            // 1. the max move steps needed between A and B is max(sum[i]), i = 0, 1, ..., n-1
            // 2. if one machine in a group has too much clothes to move out to both sides,
            //    then it needs at most max(num), i = 0, 1, ..., n-1 move steps
            // so the final anser o                                                                                                                                                                                                                                                                                                                                                 f the problem is the larger one in above two
            res = max(res, max(abs(sum), num));
        }

        return res;
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
