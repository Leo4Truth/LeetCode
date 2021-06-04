#include <iostream>
#include <vector>

using namespace std;

class Solution115 {
public:
	// exceed time limit
    int numDistinct_backtrack(string s, string t) {
        int m = s.length();
        int n = t.length();
        if (m == 0 || n == 0) return 0;

        vector<vector<int>> map(m);
        for (int i = 0; i < m; i++) {
            vector<int> tmp;
            for (int j = 0; j < n; j++) {
                if (s[i] == t[j]) tmp.push_back(j);
            }
            map.push_back(tmp);
        }

        int res = 0;
        backtrack_1(map, 0, 0, n - 1, res);

        return res;
    }
	
	void backtrack_1(vector<vector<int>> &map, int current, int target, int max, int& res) {
        if (target > max) {
            res++;
        	return;
        }
		for (int i = current; i < map.size(); i++) {
			for (int j = 0; j < map[i].size(); j++) {
                if (map[i][j] == target) backtrack_1(map, i + 1, target + 1, max, res);
			}
		}
	}

    // exceed time limit
	int numDistinct_backtrack_2(string s, string t) {
        int res = 0;

        int m = s.length();
        int n = t.length();
    	
        backtrack_2(s, t, 0, 0, res);

        return res;
    }

    void backtrack_2(string s, string t, int i, int j, int& res) {
        if (j == t.length()) {
            res++;
            return;
        }
        if (i == s.length()) return;

        if (s[i] == t[j]) backtrack_2(s, t, i + 1, j + 1, res);
    	backtrack_2(s, t, i + 1, j, res);
    }

	// dp too large
    int numDistinct_dp(string s, string t) {
        long long m = s.length();
        long long n = t.length();
        if (m == 0 || n == 0) return 0;

        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));
    	for (long long i = 0; i <= m; i++) dp[i][n] = 1;

        for (long long i = m - 1; i >= 0; i--) {
	        for (long long j = n - 1; j >= 0; j--) {
                if (s[i] == t[j]) dp[i][j] = dp[i + 1][j] + dp[i + 1][j + 1];
                else dp[i][j] = dp[i + 1][j];
	        }
        }

        return dp[0][0];
    }

    int numDistinct_dp_opt(string s, string t) {
        long long m = s.length();
        long long n = t.length();
        if (m == 0 || n == 0) return 0;

        vector<long long> dp(n, 0);

        long long prev = 1;
        for (long long i = m - 1; i >= 0; i--) {
            prev = 1;
            for (long long j = n - 1; j >= 0; j--) {
                int old_dpj = dp[j];

                if (s[i] == t[j]) dp[j] += prev;

                prev = old_dpj;
            }
        }

        return dp[0];
    }
};

int main115() {
    Solution115 solution;

    string s, t;
    cin >> s >> t;

    cout << solution.numDistinct_dp_opt(s, t) << endl;

    system("pause");

    return 0;
}