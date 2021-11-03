#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution132 {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        for (int i = 0; i < n / 2; i++) {
            if (s[i] != s[n - 1 - i]) return false;
        }
        return true;
    }
    
    // Limit Time Exceeded
    void backtrack(string& s, vector<vector<string>>& res, vector<string>& partition, int pos) {
        int n = s.size();
        if (pos == n) {
            res.push_back(partition);
            return;
        }
        
        for (int r = pos; r < n; r++) {
            int len = r - pos + 1;
            if (isPalindrome(s.substr(pos, len))) {
                partition.push_back(s.substr(pos, len));
                backtrack(s, res, partition, pos + len);
                partition.pop_back();
            }
        }
    }
    
    // Limit Time Exceeded
    int minCut_backtrack(string s) {
        int n = s.size();
        if (n == 0 || n == 1) return 0;

        vector<vector<string>> partitions;
        vector<string> partition;
        backtrack(s, partitions, partition, 0);

        int min = INT32_MAX;
        for (int i = 0; i < partitions.size(); i++) {
            int cut = partitions[i].size() - 1;
            min = cut < min ? cut : min;
        }
        return min;
    }

    int minCut_dp(string s) {
        int n = s.size();
        if (n == 0 || n == 1) return 0;

        // assume s[i : j] is the substring from s[i] to s[j] (inclusive).
        // dp[i][j] = 1, s[i : j] is palindrome
        // dp[i][j] = 0, s[i : j] is not palindrome
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
            if (i < n - 1) dp[i][i + 1] = s[i] == s[i + 1];
        }

        for (int l = n - 1; l >= 0; l--) {
            for (int r = l + 2; r < n; r++) {
                dp[l][r] = s[l] == s[r] && dp[l + 1][ r - 1] == 1;
            }
        }

#ifdef DEBUG
        for (int l = 0; l < n; l++) {
            for (int r = 0; r < n; r++) {
                cout << dp[l][r];
                if (r < n - 1) cout << " ";
            }
            cout << endl;
        }
        cout << endl;
#endif // DEBUG

        vector<int> minPalSubstrNum(n, INT32_MAX);
        for (int r = 0; r < n; r++) {
            for (int l = 0; l <= r; l++) {
                if (dp[l][r] == 1) {
                    int last = l == 0 ? 0 : minPalSubstrNum[l - 1];
                    minPalSubstrNum[r] = last + 1 < minPalSubstrNum[r] ? last + 1 : minPalSubstrNum[r];
                }
            }
        }

        return minPalSubstrNum.back() - 1;
    }

};

int main(int argc, char* argv[]) {
    string s = argc >= 2 ? argv[1] : "aab";

    Solution132 solution;
    cout << solution.minCut_dp(s) << endl;

    //system("pause");
    return 0;
}

