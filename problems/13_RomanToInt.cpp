#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	// hash table, not complete yet
	int romanToInt1(string s) {
		int nums[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
		string romans[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };

		int num = 0;
		int n = 0;

		for (int i = 0; i < 13; i++) {

		}
	}

	// most efficient approach
	int romanToInt(string s) {
		int nums[] = { 1000, 500, 100, 50, 10, 5, 1 };
		char romans[] = { 'M', 'D', 'C', 'L', 'X', 'V', 'I' };
		int num = 0;

		for (int i = 0; i < s.size() - 1; i++) {
			int x = 0, y = 0;
			while (s[i] != romans[x]) x++;
			while (s[i + 1] != romans[y]) y++;
			if (x <= y) num += nums[x];
			else num -= nums[x];
		}

		int x = 0;
		while (s[s.size() - 1] != romans[x]) x++;
		num += nums[x];

		return num;
	}
};