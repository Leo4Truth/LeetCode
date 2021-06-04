#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;

class Solution66 {
public:
	/*
	 * A limited solution which doesn't support big integer.
	 */
	/*
	vector<int> plusOne(vector<int>& digits) {
		vector<int> plusOneVec;
		if (digits.at(digits.size() - 1) != 9) {
			for (int i = 0; i < digits.size() - 1; i++) {
				plusOneVec.push_back(digits.at(i));
			}
			plusOneVec.push_back(digits.at(digits.size() - 1) + 1);
		}
		else {
			int plusOneInt = toInteger(digits) + 1;
			stack<int> stk;
			for (; plusOneInt > 0;) {
				stk.push(plusOneInt % 10);
				plusOneInt /= 10;
			}
			for (; !stk.empty();) {
				plusOneVec.push_back(stk.top());
				stk.pop();
			}
		}
		return plusOneVec;
	}
	*/

	/*
	 * A success but slow solution. 
	 */
	/*
	vector<int> plusOne(vector<int>& digits) {
		int bits = digits.size();
		stack<int> stk;
		vector<int> plusOneVec;
		for (int i = 0; i < digits.size(); i++) stk.push(digits.at(i));
		bool carry = true;
		for (; !stk.empty();) {
			int x = stk.top();
			if (carry) {
				if (x != 9) {
					plusOneVec.push_back(x + 1);
					carry = false;
				}
				else {
					plusOneVec.push_back(0);
					carry = true;
				}
			}
			else {
				plusOneVec.push_back(x);
			}
			stk.pop();
		}
		if (carry) {
			plusOneVec.push_back(1);
			carry = false;
		}
		for (int i = plusOneVec.size(); i > 0; i--)
			plusOneVec.push_back(plusOneVec.at(i - 1));
		for (int i = plusOneVec.size() / 2; i > 0; i--)
			plusOneVec.erase(plusOneVec.begin());

		return plusOneVec;
	}
	*/

	/*
	 * A simple but efficient solution
	 */
	vector<int> plusOne(vector<int>& digits) {
		for (int i = digits.size() - 1; i >= 0; i--) {
			if (digits.at(i) == 9) {
				digits.at(i) = 0;
			}
			else {
				digits.at(i) += 1;
				return digits;
			}
		}
		if (digits.at(0) == 0) digits.insert(digits.begin(), 1);
		return digits;
	}

	static int toInteger(vector<int>& digits) {
		int integer = 0;
		for (int i = 0; i < digits.size(); i++)
			integer += digits.at(digits.size() - 1 - i) * pow(10, i);

		return integer;
	}
};

int main66() {
	vector<int> digits;
	int x;
	for (;;) {
		cin >> x;
		if (x >= 0) digits.push_back(x);
		else break;
	}
	Solution66 solution66;
	vector<int> plusOneVec = solution66.plusOne(digits);
	for (int i = 0; i < plusOneVec.size(); i++) cout << plusOneVec.at(i) << " ";
	cout << endl;
	cout << "origin:   " << Solution66::toInteger(digits) << endl;
	cout << "plus one: " << Solution66::toInteger(plusOneVec) << endl;
	system("pause");
	return 0;
}