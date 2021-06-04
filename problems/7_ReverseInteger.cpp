#include <iostream>
#include <vector>

using namespace std;

class Solution7 {
public:
	int reverse(int x) {
		// deal with overflow
		if (x < INT_MIN || x > INT_MAX) {
			return 0;
		}

		// flag of positive and negative
		int flag = 1;
		if (x < 0) {
			if (x == INT_MIN) return 0;
			x = -x;
			flag = -1;
		}

		int reverse = 0;
		while (x > 0) {
			int digit = x % 10;

			// deal with overflow
			if (flag == 1 && reverse > 214748364 || reverse == 214748364 && digit > 7) return 0;
			if (flag == -1 && reverse > 214748364 || reverse == 214748364 && digit > 8) return 0;

			reverse = reverse * 10 + digit;
			x /= 10;
		}

		reverse *= flag;

		// output
		return reverse;
	}
};

int main7() {
	Solution7 solution;
	int x;
	cin >> x;
	cout << solution.reverse(x) << endl;
	system("pause");
	return 0;
}