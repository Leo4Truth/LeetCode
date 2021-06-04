#include <iostream>
#include <string>

using namespace std;

class Solution13 {
public:
	int romanToInt(string s) {
		int integer = 0;

		for (int i = 0; i < s.length(); i++) {
			// check if there is any invalid character
			char ch = s.at(i);
			if (ch != 'I' && ch != 'V' && ch != 'X' && ch != 'L' && ch != 'C' && ch != 'D' && ch != 'M') {
				cout << "Invalid Format" << endl;
				return -1;
			}
		}

		// deal with M
		for (int i = 0; i < s.length(); i++) {
			char ch = s.at(i);
			if (ch == 'M') {
				integer += 1000;
			}
			else if (ch == 'D') {
				integer += 500;
			}
			else if (ch == 'L') {
				integer += 50;
			}
			else if (ch == 'V') {
				integer += 5;
			}
			else if (ch == 'C') {
				bool flag = true;
				for (int j = i + 1; j < s.length(); j++) {
					char ch2 = s.at(j);
					if (ch2 == 'M' || ch2 == 'D') {
						integer -= 100;
						flag = false;
						break;
					}
				}
				if (flag) integer += 100;
			}
			else if (ch == 'X') {
				bool flag = true;
				for (int j = i + 1; j < s.length(); j++) {
					char ch2 = s.at(j);
					if (ch2 == 'L' || ch2 == 'C') {
						integer -= 10;
						flag = false;
						break;
					}
				}
				if (flag) integer += 10;
			}
			else if (ch == 'I') {
				bool flag = true;
				for (int j = i + 1; j < s.length(); j++) {
					char ch2 = s.at(j);
					if (ch2 == 'X' || ch2 == 'V') {
						integer -= 1;
						flag = false;
						break;
					}
				}
				if (flag) integer += 1;
			}
		}

		return integer;
	}
};
