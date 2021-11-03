#include <iostream>
#include <vector>

using namespace std;

class Solution9 {
public:
	bool isPalindrome(int x) {
		if (x < 0) return false;
		if (x == 0) return true;

		int origin = x;
		int reverse = 0;
		while (x > 0) {
			int digit = x % 10;
			if (reverse > INT_MAX / 10) return false; // deal with the overflow
			reverse = reverse * 10 + digit;
			x /= 10;
		}

		if (origin == reverse) return true;
		
		return false;
	}
};

int main9()
{
	Solution9 solution;
	int x;
	cin >> x;
	bool result = solution.isPalindrome(x);
	
	if (result) cout << "yes" << endl;
	else cout << "no" << endl;
	system("pause");
	return 0;
}