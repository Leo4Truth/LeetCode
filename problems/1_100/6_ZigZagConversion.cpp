#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution6 {
public:
	// Approach 1, no skill, beats about 90% time and 80% space
	string convert(string s, int numRows) {
		if (numRows == 1) return s; // deal with the special case

		int n = s.size();
		char *res = new char[n + 1];
		res[n] = '\0';

		int line = 0;
		int x = 0;
		int step[2] = { 2 * (numRows - 1 - x), 2 * x };
		int pos = 0;
		int flag = 0;
		for (int i = 0; i < n; i++) {
			res[i] = s[pos];
			pos = pos + step[flag];
			if (pos < n) {
				if (step[flag] == 0) {
					flag = !flag;
					pos = pos + step[flag];
				}
				else if (step[!flag] == 0);
				else flag = !flag;
			}
			else {
				line++;
				x++;
				step[0] = 2 * (numRows - 1 - x);
				step[1] = 2 * x;
				flag = 0;
				pos = line;
			}	
		}

		return string(res);
	}

	// Approach 2, Sort by Row, traverse the origin string s and fill each char into vector<string>, not efficient enough
	/*
	string convert(string s, int numRows) {
		if (numRows == 1) return s;

		vector<string> rows(min(numRows, int(s.size())));
		int curRow = 0;
		bool goingDown = false;

		for (char c : s) {
			rows[curRow] += c;
			if (curRow == 0 || curRow == numRows - 1) goingDown = !goingDown;
			curRow += goingDown ? 1 : -1;
		}

		string ret;
		for (string row : rows) ret += row;
		return ret;
	}
	*/

	// Approach 3, Visit by row, idea is similar to the approach 1, but the code is more simple
	// the speed is not as fast as Approach 1, I guess it is because the use of vector<string> which is not as efficient as operation directly on char array
	/*
	string convert(string s, int numRows) {
		if (numRows == 1) return s;

		vector<string> rows(min(numRows, int(s.size())));
		int curRow = 0;
		bool goingDown = false;

		for (char c : s) {
			rows[curRow] += c;
			if (curRow == 0 || curRow == numRows - 1) goingDown = !goingDown;
			curRow += goingDown ? 1 : -1;
		}

		string ret;
		for (string row : rows) ret += row;
		return ret;
	}
	*/

	int min(const int& a, const int& b) {
		return a < b ? a : b;
	}
};

int main6() {
	Solution6 soluution;
	string s;
	int numRows;
	cin >> s;
	cin >> numRows;
	while (s[0] != '!') {
		cout << soluution.convert(s, numRows) << endl;
		cin >> s;
		cin >> numRows;
	}
	system("pause");
	return 0;
}