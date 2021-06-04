#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution8 {
public:
	int myAtoi1(string str) {
		if (str.size() == 0) return 0;

		int i = 0;
		for (; i < str.length() && str.at(i) == ' '; i++);

		int flag = 1;
		if (i < str.size() && str.at(i) == '-') {
			flag = -1;
			i++;
		}
		else if (i < str.size() && str.at(i) == '+') {
			flag = 1;
			i++;
		}

		vector<int> digits;
		for (; i < str.length() && str.at(i) >= '0' && str.at(i) <= '9'; i++)
			digits.push_back(str.at(i) - '0');

		int res = 0;
		for (int i = 0; i < digits.size(); i++) {
			int t = digits.at(i) * flag;

			if (res > INT_MAX / 10 || res == INT_MAX / 10 && t > 7) return INT_MAX;
			if (res < INT_MIN / 10 || res == INT_MIN / 10 && t < -8) return INT_MIN;

			res *= 10;
			res += t;
		}

		return res;
	}

	int myAtoi(string str) {
		if (str.size() == 0) return 0;

		int i = 0;
		for (; i < str.length() && isspace(str[i]); i++);

		int flag = 1;
		if (i < str.size() && str[i] == '-') {
			flag = -1;
			i++;
		}
		else if (i < str.size() && str[i] == '+') {
			flag = 1;
			i++;
		}

		int res = 0;
		for (; i < str.length() && isdigit(str[i]); i++) {
			int t = (str[i] - '0') * flag;

			if (res > INT_MAX / 10 || res == INT_MAX / 10 && t > 7) return INT_MAX;
			if (res < INT_MIN / 10 || res == INT_MIN / 10 && t < -8) return INT_MIN;

			res *= 10;
			res += t;
		}

		return res;
	}
};

int main8() {
	Solution8 solution;
	string str = "";
	//cin >> str;
	cout << solution.myAtoi(str) << endl;
	system("pause");
	return 0;
}