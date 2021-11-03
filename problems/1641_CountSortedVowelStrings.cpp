#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<char> vowels {'a', 'e', 'i', 'o', 'u'};
    unordered_map<char, int> index{
        {'a', 0},
        {'e', 1},
        {'i', 2},
        {'o', 3},
        {'u', 4}
    };

    void backtrack_1(string s, int n, int& cnt) {
        int len = s.length();
        int idx = 0;
        if (len == n) {
            cnt++;
            return;
        }
        else if (len == 0) idx = 0;
        else idx = index[s[len - 1]];

        if (idx == 4) cnt++;
        else {
            for (int i = idx; i < 5; i++)
                backtrack_1(s + vowels[i], n, cnt);
        }
    }

    int countVowelStrings_bk_1(int n) {
        int cnt = 0;
        string s = "";
        backtrack_1(s, n, cnt);
        return cnt;
    }

    int backtrack_2(int n, int vowels) {
        if (n == 0) return 1;
        int res = 0;
        for (int i = vowels; i < 5; i++)
            res += backtrack_2(n - 1, i);
        return res;
    }

    int countVowelStrings_bk_2(int n) {
        return backtrack_2(n, 0);
    }

    int countVowelStrings_dp_bottom_up(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(6, 0));
        for (int vowels = 1; vowels <= 5; vowels++) dp[1][vowels] = vowels;
        for (int nn = 0; nn < n; nn++) {
            dp[n][1] = 1;
            for (int vowels = 2; vowels <= 5; vowels++)
                dp[nn][vowels] = dp[nn][vowels - 1] + dp[nn - 1][vowels];
        }
        return dp[n][5];
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 5;
    Solution solution;
    cout << solution.countVowelStrings(n) << endl;
    return 0;
}