#include <iostream>
#include <vector>

using namespace std;

class Solution87 {
public:
    bool isScramble(string s1, string s2) {
		if (s1.size() != s2.size()) return false;
		int n = s1.size();
		vector<vector<vector<bool>>> dp(n);
		// initalize the single char situation
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dp[i].push_back(vector<bool>(n + 1, false));
				dp[i][j][1] = s1[i] == s2[j];
			}
		}
		/*
		for (int k = 1; k < n; k++) {
			cout << "len = " << k << endl;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					cout << dp[i][j][k] << " ";
				}
				cout << endl;
			}
			cout << endl;
		}
		*/
		// len
		for (int k = 2; k <= n; k++) {
			// start pos of S
			// the end of S i+k-1 <= n-1, so i <= n-k
			for (int i = 0; i <= n - k; i++) {
				// start pos of T
				// the end of T j+k-1 <= n-1, so j <= n-k
				for (int j = 0; j <= n - k; j++) {
					// split pos
					for (int w = 1; w <= k - 1; w++) {
						// S1 ==> T1, S2 ==> T2
						// S[i...i+w-1] ==> T[j...j+w-1] and S[i+w...i+k-1] ==> T[j+w...j+k-1]
						if (dp[i][j][w] && dp[i + w][j + w][k - w]) {
							dp[i][j][k] = true;
							break;
						}
						// S1 ==> T2, S2 ==> T1
						// S[i...i+w-1] ==> T[j+k-w...j+k-1] and S[i+w...i+k-1] ==> T[j...j+k-w-1]
						if (dp[i][j + k - w][w] && dp[i + w][j][k - w]) {
							dp[i][j][k] = true;
							break;
						}
					}
				}
			}
		}
		/*
		for (int k = 1; k < n; k++) {
			cout << "len = " << k << endl;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					cout << dp[i][j][k] << " ";
				}
				cout << endl;
			}
			cout << endl;
		}
		*/
		return dp[0][0][n];
    }
};

int main87() {
	Solution87 solution;
	string s1, s2;
	cin >> s1 >> s2;
	cout << solution.isScramble(s1, s2) << endl;
	system("pause");
	return 0;
}