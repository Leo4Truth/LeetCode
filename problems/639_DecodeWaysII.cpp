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
private:
    static constexpr int MOD = 1e9+7;

public:
    int numDecodings(string s) {
        auto check1digit = [](char ch) -> int {
            if (ch == '0') return 0;
            return ch == '*' ? 9 : 1;
        };

        auto check2digits = [](char ch0, char ch1) -> int {
            if (ch0 == '*' && ch1 == '*') return 15; // **: 9 + 6
            if (ch0 == '*') return ch1 <= '6' ? 2 : 1; // *[123456]: 2, *[789]: 1
            if (ch1 == '*') {
                if (ch0 == '1') return 9; // 1*: 9
                if (ch0 == '2') return 6; // 2*: 6
                return 0; // [3456789]*: 0
            }
            return ch0 != '0' && (ch0 - '0') * 10 + (ch1 - '0') <= 26; // if no *, [1, ..., 26]: 1, [0, 27, ...]: 0
        };

        int n = s.size();
        // a = f[i-2], b = f[i-1], c = f[i]
        int a = 0, b = 1, c = 0;
        for (int i = 1; i <= n; ++i) {
            c = (long long)b * check1digit(s[i - 1]) % MOD;
            if (i > 1) c = (c + (long long)a * check2digits(s[i - 2], s[i - 1])) % MOD;
            a = b;
            b = c;
        }

        return c;
    }
};

int main(int argc, char* argv[]) {
    // 输入 * 时须转义 (\*)
    string s = argc >= 2 ? argv[1] : "";

    Solution solution;
    cout << solution.numDecodings(s) << endl;
    
    return 0;
}
