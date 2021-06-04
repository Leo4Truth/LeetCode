#include <iostream>
#include <vector>

using namespace std;

class Solution17 {
public:
	char lettersTable[8][4] = {
		{'a', 'b', 'c', 0},
		{'d', 'e', 'f', 0},
		{'g', 'h', 'i', 0},
		{'j', 'k', 'l', 0},
		{'m', 'n', 'o', 0},
		{'p', 'q', 'r', 's'},
		{'t', 'u', 'v', 0},
		{'w', 'x', 'y', 'z'}
	};

	vector<string> letterCombinations(string digits) {
		vector<string> res;
		backtrack(res, "", digits);
		return res;
	}

	void backtrack(vector<string>& res, string combination, string next_digits) {
		if (next_digits.empty()) {
			if (!combination.empty()) res.push_back(combination);
			return;
		}
		char digit = next_digits.at(0);
		vector<char> letters;
		for (int i = 0; i < 4; i++) {
			char ch = lettersTable[digit - '2'][i];
			if (ch != 0) backtrack(res, combination + ch, next_digits.substr(1, next_digits.length() - 1));
		}
	}
};

int main17() {
	Solution17 solution;
	string digits;
	cin >> digits;
	vector<string> res = solution.letterCombinations(digits);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << endl;
	system("pause");
	return 0;
}