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
    virtual int maxCount(int m, int n, vector<vector<int>>& ops) = 0;
};

class Solution_intersection : public Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int mina = m, minb = n;
        for (const auto& op: ops) {
            mina = min(mina, op[0]);
            minb = min(minb, op[1]);
        }
        return mina * minb;
    }

private:
};

int main(int argc, char* argv[]) {
    int m = argc >= 2 ? stoi(argv[1]) : 0;
    int n = argc >= 3 ? stoi(argv[2]) : 0;
    vector<vector<int>> ops;
    for (int i = 0; i < n; i++) {
        vector<int> op;
        int a;
        int b;
        cin >> a >> b;
        ops.push_back({a, b});
    }

    Solution *solution = nullptr;

    solution = new Solution_intersection();
    cout << "intersection: " << solution->maxCount(m, n, ops) << endl;

    return 0;
}
