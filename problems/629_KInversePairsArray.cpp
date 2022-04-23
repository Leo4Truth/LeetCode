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
    virtual int kInversePairs(int n, int k) = 0;
    static constexpr int mod = 1000000007;
};

class Solution_dp_optimized : public Solution {
public:
    int kInversePairs(int n, int k) {
        vector<vector<int>> f(2, vector<int>(k + 1, 0));
        f[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                int cur = i & 1;
                int prev = cur ^ 1;
                f[cur][j] = (j - 1 >= 0 ? f[cur][j - 1] : 0) - (j - i >= 0 ? f[prev][j - i] : 0) + f[prev][j];
                if (f[cur][j] >= mod) f[cur][j] -= mod;
                else if (f[cur][j] < 0) f[cur][j] += mod;
            }
        }
        return f[n & 1][k];
    }

private:
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    int k = argc >= 3 ? stoi(argv[2]) : 0;

    Solution *solution = nullptr;

    solution = new Solution_dp_optimized();
    cout << solution->kInversePairs(n, k) << endl;

    return 0;
}
