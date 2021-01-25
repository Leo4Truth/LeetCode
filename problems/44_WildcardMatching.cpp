#include <iostream>
#include <vector>

using namespace std;

class Solution44 {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        // dp[i][j] = true --> s[0, i - 1] matches p[0, j - 1]
        dp[0][0] = true;
        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == '*') dp[0][j] = dp[0][j - 1];
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] == '*') dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                if (p[j - 1] == '?' || p[j - 1] == s[i - 1]) dp[i][j] = dp[i - 1][j - 1];
            }
        }
        return dp[m][n];
    }

    bool isLowerLetter(char c) {
        return c <= 'z' && c >= 'a';
    }

    bool isValidPattern(char c) {
        return (c <= 'z' && c >= 'a') || c == '?' || c == '*';
    }

    int stringMatch(string s, string p) {
        for (int i = 0; i < s.size(); i++) {
            bool match = true;
            for (int j = 0; j < p.size(); j++) {
                if (i + j >= s.size()) return -1;
                if (s[i + j] != p[j]) {
                    match = false;
                    break;
                }
            }
            if (match) return i;
        }
    }
};

int main44() {
    Solution44 solution;
    string s, p;
    cin >> s;
    cin >> p;
    cout << solution.isMatch(s, p) << endl;
    system("pause");
    return 0;
}