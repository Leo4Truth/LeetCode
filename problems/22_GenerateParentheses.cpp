#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
	vector<string> generateParenthesisRecursive(int n) {
		vector<string> results;

		if (n == 0) {
			results.push_back("");
		}
		else {
			for (int c = 0; c < n; c++) {
				vector<string> strs_c = generateParenthesisRecursive(c);
				for (int i = 0; i < strs_c.size(); i++) {
					vector<string> strs_N_1_c = generateParenthesisRecursive(n - 1 - c);
					for (int j = 0; j < strs_N_1_c.size(); j++) {
						results.push_back("(" + strs_c[i] + ")" + strs_N_1_c[j]);
					}
				}
			}
		}

		return results;
	}

	vector<string> generateParenthesisBackTracking(int n) {
		vector<string> results;
		backTrack(results, "", 0, 0, n);
		return results;
	}

	void backTrack(vector<string>& results, string current, int open, int close, int max) {
		if (current.size() == 2 * max) {
			results.push_back(current);
			return;
		}

		if (open < max) backTrack(results, current + "(", open + 1, close, max);
		if (close < open ) backTrack(results, current + ")", open, close + 1, max);
	}
};