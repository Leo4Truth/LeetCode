#include <iostream>
#include <vector>

using namespace std;

class Solution91 {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0) return 0;
        vector<int> dp(n + 1, 0);
        dp[n] = 1;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') continue;
            dp[i] = dp[i + 1];
            if (i < n - 1 && (s[i] - '0') * 10 + s[i + 1] - '0' <= 26) dp[i] += dp[i + 2];
        }
        return dp[0];
    }
};

int main91() {
    Solution91 solution;
    string s;
    cin >> s;
    cout << solution.numDecodings(s) << endl;
    system("pause");
    return 0;
}