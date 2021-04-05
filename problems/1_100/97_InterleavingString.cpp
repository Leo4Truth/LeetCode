#include <iostream>
#include <vector>

using namespace std;

class Solution97 {
public:
    bool isInterleave(string s1, string s2, string s3) {
		int m = s1.size(), n = s2.size();
		if (s3.size() != m + n) return false;
		vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
		dp[0][0] = true;
		for (int i = 1; i <= m && s1[i - 1] == s3[i - 1]; i++) dp[i][0] = true;
		for (int j = 1; j <= n && s2[j - 1] == s3[j - 1]; j++) dp[0][j] = true;
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) ||
					(dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
			}
		}
		return dp[m][n];
    }
};

int main97() {
	Solution97 solution;
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	cout << s1 << endl << s2 << endl << s3 << endl;
	cout << solution.isInterleave(s1, s2, s3) << endl;
	system("pause");
	return 0;
}