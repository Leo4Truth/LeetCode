#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution12 {
public:
	// initial solution without set up a table
	string intToRoman1(int num) {
		vector<char> roman;
		int m, cm, d, cd, c, xc, l, xl, x, ix, v, iv, i;

		m = num / 1000;
		num -= m * 1000;

		cm = num / 900;
		num -= cm * 900;

		d = num / 500;
		num -= d * 500;

		cd = num / 400;
		num -= cd * 400;

		c = num / 100;
		num -= c * 100;

		xc = num / 90;
		num -= xc * 90;

		l = num / 50;
		num -= l * 50;

		xl = num / 40;
		num -= xl * 40;

		x = num / 10;
		num -= x * 10;

		ix = num / 9;
		num -= ix * 9;

		v = num / 5;
		num -= v * 5;

		iv = num / 4;
		num -= iv * 4;

		i = num;


		for (int j = 0; j < m; j++) roman.push_back('M');
		for (int j = 0; j < cm; j++) {
			roman.push_back('C');
			roman.push_back('M');
		}
		for (int j = 0; j < d; j++) roman.push_back('D');
		for (int j = 0; j < cd; j++) {
			roman.push_back('C');
			roman.push_back('D');
		}
		for (int j = 0; j < c; j++) roman.push_back('C');
		for (int j = 0; j < xc; j++) {
			roman.push_back('X');
			roman.push_back('C');
		}
		for (int j = 0; j < l; j++) roman.push_back('L');
		for (int j = 0; j < xl; j++) {
			roman.push_back('X');
			roman.push_back('L');
		}
		for (int j = 0; j < x; j++) roman.push_back('X');
		for (int j = 0; j < ix; j++) {
			roman.push_back('I');
			roman.push_back('X');
		}
		for (int j = 0; j < v; j++) roman.push_back('V');
		for (int j = 0; j < iv; j++) {
			roman.push_back('I');
			roman.push_back('V');
		}
		for (int j = 0; j < i; j++) roman.push_back('I');

		string res = "";
		for (int i = 0; i < roman.size(); i++) res += roman[i];

		return res;
	}

	// set up a table, same effeciency, better code
	string intToRoman(int num) {
		int nums[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
		string romans[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
		string roman = "";

		for (int i = 0; i < 13; i++) {
			int t = num / nums[i];
			num -= nums[i] * t;
			for (int j = 0; j < t; j++) roman += romans[i];
		}

		return roman;
	}
};

int main12() {
	Solution12 solution;
	int num;
	cin >> num;
	cout << solution.intToRoman(num) << endl;
	system("pause");
	return 0;
}