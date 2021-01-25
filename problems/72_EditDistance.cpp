#include <iostream>
#include <vector>

using namespace std;

class Solution72 {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1);
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                dp[i].push_back(0);
            }
        }
        for (int i = 0; i <= m; i++) dp[i][0] = i;
        for (int j = 1; j <= n; j++) dp[0][j] = j;
        //print(dp);

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else dp[i][j] = min(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]) + 1;
            }
        }
        //print(dp);

        return dp[m][n];
    }

    int min(const int& a, const int& b, const int& c) {
        int x = a < b ? a : b;
        return x < c ? x : c;
    }

    void print(vector<vector<int>>& dp) {
        int m = dp.size();
        if (m == 0) return;
        int n = dp[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << dp[i][j] << "  ";
            }
            cout << endl;
        }
        cout << endl;
    }
};

int main72() {
	Solution72 solution;
    string word1, word2;
    cin >> word1 >> word2;
    cout << solution.minDistance(word1, word2) << endl;
    system("pause");
    return 0;
}