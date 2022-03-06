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
    virtual int superPow(int a, vector<int>& b) = 0;
};

/**
 * @brief 快速幂, 秦九韶算法 (正序遍历)
 */
cclass Solution_preorderQuickPow : public Solution {
public:
    int superPow(int a, vector<int> &b) {
        int ans = 1;
        for (int e: b) {
            ans = (long) pow(ans, 10) * pow(a, e) % MOD;
        }
        return ans;
    }

private:
    const int MOD = 1337;

    int pow(int x, int n) {
        int res = 1;
        while (n) {
            if (n % 2) {
                res = (long) res * x % MOD;
            }
            x = (long) x * x % MOD;
            n /= 2;
        }
        return res;
    }
};


/**
 * @brief 快速幂, 倒序遍历
 */
class Solution_postorderQuickPow : public Solution {
public:
    int superPow(int a, vector<int> &b) {
        int ans = 1;
        for (int i = b.size() - 1; i >= 0; --i) {
            ans = (long) ans * pow(a, b[i]) % MOD;
            a = pow(a, 10);
        }
        return ans;
    }

private:
    const int MOD = 1337;

    int pow(int x, int n) {
        int res = 1;
        while (n) {
            if (n % 2) {
                res = (long) res * x % MOD;
            }
            x = (long) x * x % MOD;
            n /= 2;
        }
        return res;
    }
};

int main(int argc, char* argv[]) {
    int a = argc >= 2 ? stoi(argv[1]) : 0;
    int n = argc >= 3 ? stoi(argv[2]) : 0;
    vector<int> b;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        b.push_back(x);
    }

    Solution *solution = nullptr;

    solution = new Solution_quickPow();
    cout << solution->superPow(a, b) << endl;

    return 0;
}
